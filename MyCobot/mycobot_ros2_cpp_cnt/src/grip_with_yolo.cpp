  
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>

#include <rclcpp/rclcpp.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <geometry_msgs/msg/pose.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <mycobot_interfaces/srv/detection_rq.hpp>
#include <mycobot_interfaces/srv/state_rq.hpp>
#include <moveit/kinematic_constraints/utils.h>
#include <cmath>
#include <std_msgs/msg/int32.hpp>

using namespace std::chrono_literals;
using namespace std;


#define CAMFOCUS_X 306
#define CAMFOCUS_Y 285

vector<tuple<string,float,float,float,float>> detected_list;
geometry_msgs::msg::Pose target_pose;
geometry_msgs::msg::Pose current_pose;
sensor_msgs::msg::JointState arm_target_joint;
sensor_msgs::msg::JointState hand_target_joint;

string detectionList[6] = {"box", "clay", "cube", "eclipse", "profile", "soap"};
bool isCorrectId = true;


bool planAndExecute(moveit::planning_interface::MoveGroupInterface& move_group_interface, moveit::planning_interface::MoveGroupInterface::Plan& plan, rclcpp::Logger logger) {
    bool success = static_cast<bool>(move_group_interface.plan(plan));
    if (success) {
        move_group_interface.execute(plan);
        RCLCPP_INFO(logger, "Execution successful!");
        return true;
    } else {
        RCLCPP_ERROR(logger, "Planning failed!");
        return false;
    }
}


tuple<double, double, double> quaternionToRPY(const geometry_msgs::msg::Quaternion& quaternion){
    tf2::Quaternion tf_quaternion;
    tf2::fromMsg(quaternion, tf_quaternion);

    double roll, pitch, yaw;
    tf2::Matrix3x3(tf_quaternion).getRPY(roll, pitch, yaw);
    return {roll, pitch, yaw};
}

geometry_msgs::msg::Quaternion rpyToQuaternion(double roll, double pitch, double yaw) {
    tf2::Quaternion quaternion;
    quaternion.setRPY(roll, pitch, yaw);

    geometry_msgs::msg::Quaternion msg_quaternion;
    msg_quaternion.x = quaternion.x();
    msg_quaternion.y = quaternion.y();
    msg_quaternion.z = quaternion.z();
    msg_quaternion.w = quaternion.w();

    return msg_quaternion;
}

void detectionRequest(rclcpp::Node::SharedPtr detection_request_node, rclcpp::Logger logger) {
    detected_list.clear();

    auto detection_client = detection_request_node->create_client<mycobot_interfaces::srv::DetectionRQ>("yolo_detection");
    auto detection_request = make_shared<mycobot_interfaces::srv::DetectionRQ::Request>();

    detection_request->trigger = true;
    if (!detection_client->wait_for_service(1s)) {
        RCLCPP_ERROR(logger, "Service not available, exiting.");
        return;
    }

    auto detection_result = detection_client->async_send_request(detection_request);

    if (rclcpp::spin_until_future_complete(detection_request_node, detection_result) == rclcpp::FutureReturnCode::SUCCESS){
        auto detections = detection_result.get()->result.detections;
        for (auto &detection : detections){
            auto color = detection.id;
            auto centerx = detection.bbox.center.position.x;
            auto centery = detection.bbox.center.position.y;
            auto angle = detection.bbox.center.theta;
            float m_per_pixel = 0.000833333;
            detected_list.push_back({color, centerx, centery, angle, m_per_pixel});
        }
    } else {
        RCLCPP_ERROR(logger, "Failed to call service detection");
    }
}

tuple<bool,int,int,float> checkMidPoint(string target_name ,rclcpp::Node::SharedPtr detection_request_node, rclcpp::Logger logger){
    detectionRequest(detection_request_node,logger);
    int idx = 0, dy=0, dx=0;
    float theta=0;
    bool alignment_flag=false;

    for(auto& elem:detected_list){

        if (get<0>(elem) == target_name){
            int new_dx = (get<1>(elem) - CAMFOCUS_X);
            int new_dy = (CAMFOCUS_Y - get<2>(elem));
            if(abs(dx)+abs(dy)<abs(new_dy)+abs(new_dx)){
                dy=new_dy;
                dx=new_dx;
                theta = get<3>(detected_list[idx]);
            }
        }
    }

    if(abs(dx)<15 && abs(dy)<15) alignment_flag = true;
    return{alignment_flag,dx,dy,theta};
}


void gripper_set(rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher, int value, rclcpp::Logger logger) {
    std_msgs::msg::Int32 msg;
    msg.data = value;
    publisher->publish(msg);
    RCLCPP_INFO(logger, "Publishing: '%d'", msg.data);
}

void performTask(int itemId, 
                 moveit::planning_interface::MoveGroupInterface& arm_move_group_interface,
                 moveit::planning_interface::MoveGroupInterface& hand_move_group_interface, 
                 moveit::planning_interface::MoveGroupInterface::Plan& plan, 
                 rclcpp::Logger logger, rclcpp::Node::SharedPtr detection_request_node) {
    
    isCorrectId = true;
                     
    while (isCorrectId) {
        arm_move_group_interface.setNamedTarget("home");
        planAndExecute(arm_move_group_interface, plan, logger);
        this_thread::sleep_for(2s);


        string target_name;
        float center_x;
        float center_y;
        float target_theta;
        float m_per_pixel;
        bool detection_flag=true;

        // 
        while (detection_flag){
            detectionRequest(detection_request_node, logger);
            for (auto& elem:detected_list){
                cout<<get<0>(elem)<<" "<<get<1>(elem)<<" "<<get<2>(elem)<<" "<<get<3>(elem)<<"\n";
            }

            vector<tuple<string,float,float,float,float>> tempv;
            for(auto& elem:detected_list){
                center_x = get<1>(elem);
                center_y = get<2>(elem);
                if (center_y<240||center_y>290||center_x<270||center_x>360) continue;
                tempv.push_back(elem);

            }
            if(tempv.size()==0){
                cout<<"noting detected\n";
                this_thread::sleep_for(2s);
                continue;
            }
            if(tempv.size()>1){
                cout<<"over 2 cube detected\n";
                this_thread::sleep_for(2s);
                continue;
            }
            target_name = get<0>(tempv[0]);
            center_x = get<1>(tempv[0]);
            center_y = get<2>(tempv[0]);
            target_theta = get<3>(tempv[0]);
            m_per_pixel = get<4>(tempv[0]);

            if (target_name != detectionList[itemId]) {
                isCorrectId = false;
            }

            cout<<"target box color: "<<target_name<<"   center point: ("<<center_x<<","<<center_y<<")   theta: "<<target_theta<<" \n";
 
            break;
        }
        detection_flag=true;
        if (!isCorrectId) break;
        

        arm_move_group_interface.setNamedTarget("grip_ready");
        planAndExecute(arm_move_group_interface, plan, logger);
        this_thread::sleep_for(4s);


        // rotate alignment 
        if (target_theta>45)target_theta=(target_theta-90)*M_PI/180;
        else target_theta=target_theta*M_PI/180;
        current_pose = arm_move_group_interface.getCurrentPose().pose;
        target_pose = current_pose;

        vector<string> jointname = arm_move_group_interface.getJointNames();
        vector<double> jointstate = arm_move_group_interface.getCurrentJointValues();
        int cnt=0;
        for(auto& elem:jointname){
            if(elem=="joint6output_to_joint6") jointstate[cnt]+=target_theta;
            cnt++;
        }
        arm_target_joint.name=jointname;
        arm_target_joint.position=jointstate;
        arm_move_group_interface.setJointValueTarget(arm_target_joint);
        planAndExecute(arm_move_group_interface, plan, logger);
        this_thread::sleep_for(2s);


        // hand open
        hand_move_group_interface.setNamedTarget("halfopen");
        planAndExecute(hand_move_group_interface,plan,logger);
        this_thread::sleep_for(1s);

        current_pose = arm_move_group_interface.getCurrentPose().pose;
        float end_Y = arm_move_group_interface.getCurrentRPY()[2];
        float dx=(center_x - CAMFOCUS_X) * m_per_pixel;
        float dy=(center_y - CAMFOCUS_Y) * m_per_pixel;


        //
        float position_x = 0.260292 + dy;
        float position_y = -0.059913 + dx;
        
        
        //move pose
        //Cartesian path plan   
        std::vector<geometry_msgs::msg::Pose> waypoints;

        current_pose = arm_move_group_interface.getCurrentPose().pose;
        target_pose=current_pose;
        target_pose.position.x=position_x;
        target_pose.position.y=position_y;
        target_pose.position.z=0.28;
        waypoints.push_back(target_pose);


        target_pose.position.z-=0.02;
        waypoints.push_back(target_pose);

        
        moveit_msgs::msg::RobotTrajectory trajectory;
        const double jump_threshold = 0.0;
        const double eef_step = 0.001;
        double fraction = arm_move_group_interface.computeCartesianPath(waypoints,eef_step,jump_threshold,trajectory);
        arm_move_group_interface.execute(trajectory);

        this_thread::sleep_for(2s);

        if (target_name.compare("eclipse") == 0) {
            hand_move_group_interface.setNamedTarget("grip_eclipse");
        }
        else if(target_name.compare("cube") == 0){
            hand_move_group_interface.setNamedTarget("grip_cube");
        }
        else if(target_name.compare("clay") == 0){
            hand_move_group_interface.setNamedTarget("grip_clay");
        }
        else if(target_name.compare("soap") == 0 || target_name.compare("box") == 0){
            hand_move_group_interface.setNamedTarget("grip_etc");
            
        }

        // hand_move_group_interface.setNamedTarget("grip");
        planAndExecute(hand_move_group_interface,plan,logger);
        this_thread::sleep_for(1s);



        ////drop cube;

        waypoints.clear();

        current_pose = arm_move_group_interface.getCurrentPose().pose;
        target_pose=current_pose;
        waypoints.push_back(target_pose);


        arm_move_group_interface.setNamedTarget("drop");
        planAndExecute(arm_move_group_interface, plan, logger);
        this_thread::sleep_for(1s);

        hand_move_group_interface.setNamedTarget("halfopen");
        planAndExecute(hand_move_group_interface,plan,logger);
        this_thread::sleep_for(1s);
        

        //// ready,close
        arm_move_group_interface.setNamedTarget("home");
        planAndExecute(arm_move_group_interface,plan,logger);
        this_thread::sleep_for(2s);
        
        hand_move_group_interface.setNamedTarget("close");
        planAndExecute(hand_move_group_interface,plan,logger);
        this_thread::sleep_for(1s);
        

        // cout<<"if want to stop press 1 , test again press 0 : ";
        // cin>>stop_flag;
        cout<<"drop & drop  done wait 2s";
        this_thread::sleep_for(2s);
    }
}

void handleServiceRequest(const std::shared_ptr<mycobot_interfaces::srv::StateRQ::Request> request, 
                          std::shared_ptr<mycobot_interfaces::srv::StateRQ::Response> response, 
                          moveit::planning_interface::MoveGroupInterface& arm_move_group_interface, 
                          moveit::planning_interface::MoveGroupInterface& hand_move_group_interface, 
                          moveit::planning_interface::MoveGroupInterface::Plan& plan, 
                          rclcpp::Logger service_logger ,
                          rclcpp::Logger logger, 
                          rclcpp::Node::SharedPtr detection_request_node) {

    if (request->trigger) {
        performTask(request->target, arm_move_group_interface, hand_move_group_interface, plan, logger, detection_request_node);
        response->endflag = isCorrectId;
        response->result = 0;
        RCLCPP_INFO(service_logger, "task End");
    }
}


int main(int argc, char* argv[]) {  

    rclcpp::init(argc, argv);

    auto node = make_shared<rclcpp::Node>("grip_with_yolo_node", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
    auto const logger =rclcpp::get_logger("grip_with_yolo_node");
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    thread spinner = thread([&executor]() { executor.spin(); });

    //cube detection 을 위한 노드 생성
    rclcpp::Node::SharedPtr detection_request_node = rclcpp::Node::make_shared("detection_request_node");

    using moveit::planning_interface::MoveGroupInterface;
    auto arm_move_group_interface = MoveGroupInterface(node, "mycobot_arm");
    auto hand_move_group_interface = MoveGroupInterface(node, "hand");
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    geometry_msgs::msg::Quaternion quat_msg;

    
    // moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    // auto objectname=planning_scene_interface.getKnownObjectNames();
    // for (auto& elem:objectname) cout<< elem<< " \n";


    // Service
    auto task_service_node = make_shared<rclcpp::Node>("end_detection_node");
    auto const task_service_logger = rclcpp::get_logger("end_detection_node");
    auto service = task_service_node->create_service<mycobot_interfaces::srv::StateRQ>(
        "end_detection",
        [&](const std::shared_ptr<mycobot_interfaces::srv::StateRQ::Request> request,
            std::shared_ptr<mycobot_interfaces::srv::StateRQ::Response> response) {
            handleServiceRequest(request, response, arm_move_group_interface,hand_move_group_interface, plan, task_service_logger ,logger, detection_request_node);
        });
    
    rclcpp::spin(task_service_node);
    rclcpp::shutdown();
    return 0;
}