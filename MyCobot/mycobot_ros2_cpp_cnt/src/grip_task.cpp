#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
#include <thread>

#include <rclcpp/rclcpp.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <std_msgs/msg/int32.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <mycobot_interfaces/srv/detection_rq.hpp>
#include <mycobot_interfaces/srv/state_rq.hpp>
#include <moveit/kinematic_constraints/utils.h>
#include <cmath>


using namespace std::chrono_literals;
using namespace std;

#define CAMFOCUS_X 320
#define CAMFOCUS_Y 240

vector<tuple<string, float, float, float, float>> detected_object;
geometry_msgs::msg::Pose target_pose;
geometry_msgs::msg::Pose current_pose;
sensor_msgs::msg::JointState arm_target_joint;
sensor_msgs::msg::JointState hand_target_joint;



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

tuple<double, double, double> quaternionToRPY(const geometry_msgs::msg::Quaternion& quaternion) {
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
    detected_object.clear();

    auto detection_client = detection_request_node->create_client<mycobot_interfaces::srv::DetectionRQ>("yolo_detection");
    auto detection_request = make_shared<mycobot_interfaces::srv::DetectionRQ::Request>();

    detection_request->trigger = true;
    if (!detection_client->wait_for_service(1s)) {
        RCLCPP_ERROR(logger, "Service not available, exiting.");
        return;
    }

    auto detection_result = detection_client->async_send_request(detection_request);

    if (rclcpp::spin_until_future_complete(detection_request_node, detection_result) == rclcpp::FutureReturnCode::SUCCESS) {
        auto detections = detection_result.get()->result.detections;
        for (auto& detection : detections) {
            auto id = detection.id;
            auto centerx = detection.bbox.center.position.x;
            auto centery = detection.bbox.center.position.y;
            auto angle = detection.bbox.center.theta;
            float m_per_pixel = 0.00159;
            detected_object.push_back({id, centerx, centery, angle, m_per_pixel});
        }
    } else {
        RCLCPP_ERROR(logger, "Failed to call service detection");
    }
}

auto addCollision(moveit::planning_interface::MoveGroupInterface& move_group_interface) {
    auto const collision_object = [frame_id = move_group_interface.getPlanningFrame()] {
        moveit_msgs::msg::CollisionObject collision_object;
        collision_object.header.frame_id = frame_id;
        collision_object.id = "conveyor";
        shape_msgs::msg::SolidPrimitive primitive;

        // Define the size of the box in meters
        primitive.type = primitive.BOX;
        primitive.dimensions.resize(3);
        primitive.dimensions[primitive.BOX_X] = 0.13;
        primitive.dimensions[primitive.BOX_Y] = 0.3;
        primitive.dimensions[primitive.BOX_Z] = 0.09;

        // Define the pose of the box (relative to the frame_id)
        geometry_msgs::msg::Pose box_pose;
        box_pose.orientation.w = 1.0;
        box_pose.position.x = 0.075 + 0.13 / 2;
        box_pose.position.y = 0.12 + 0.15;
        box_pose.position.z = primitive.dimensions[primitive.BOX_Z] / 2 - 0.06;

        collision_object.primitives.push_back(primitive);
        collision_object.primitive_poses.push_back(box_pose);

        shape_msgs::msg::SolidPrimitive left_side;
        left_side.type = left_side.BOX;
        left_side.dimensions.resize(3);
        left_side.dimensions[primitive.BOX_X] = 0.04;
        left_side.dimensions[primitive.BOX_Y] = 0.3;
        left_side.dimensions[primitive.BOX_Z] = 0.80;

        box_pose.orientation.w = 1.0;
        box_pose.position.x = 0.075 + 0.13 + 0.02;
        box_pose.position.y = 0.12 + 0.15;
        box_pose.position.z = 0.4;
        collision_object.primitives.push_back(left_side);
        collision_object.primitive_poses.push_back(box_pose);

        collision_object.operation = collision_object.ADD;
        return collision_object;
    }();
    return collision_object;
}

void gripper_set(rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher, int value, rclcpp::Logger logger) {
    std_msgs::msg::Int32 msg;
    msg.data = value;
    publisher->publish(msg);
    RCLCPP_INFO(logger, "Publishing: '%d'", msg.data);
}

void performTask(int num, moveit::planning_interface::MoveGroupInterface& arm_move_group_interface, moveit::planning_interface::MoveGroupInterface::Plan& plan, rclcpp::Logger logger, rclcpp::Node::SharedPtr detection_request_node, rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr gripper_state) {
    while (num--) {
        // int keywait;
        // current_pose = arm_move_group_interface.getCurrentPose().pose;
        // cout << "current_pose : "<<current_pose.position.x<<" "<<current_pose.position.y<<" "<<current_pose.position.z<<" "<<current_pose.orientation.w<<" "<<current_pose.orientation.x<<" "<<current_pose.orientation.y<<" "<<current_pose.orientation.z<<" \n";
        // cin>>keywait;
        arm_move_group_interface.setNamedTarget("detect_ready");
        planAndExecute(arm_move_group_interface, plan, logger);
        std::this_thread::sleep_for(2s);

        detected_object.clear();
        while(true){
            if (detected_object.empty()) {
                RCLCPP_INFO(logger, "detecting...");
                detectionRequest(detection_request_node, logger);
                std::this_thread::sleep_for(2s);
            }else break;
        }
        auto id = get<0>(detected_object[0]);
        auto cx = get<1>(detected_object[0]);
        auto cy = get<2>(detected_object[0]);
        // cout<< cx<<" "<<cy<<"\n";
        float target_x = -0.16 + cx + 0.04; 
        float target_y = 0.13 - cy + 0.025;
        // cout<< target_x<<" "<<target_y<<"\n";
        // cin>>keywait;

        arm_move_group_interface.setNamedTarget("grip_ready");
        planAndExecute(arm_move_group_interface, plan, logger);
        std::this_thread::sleep_for(2s);


        std::vector<geometry_msgs::msg::Pose> waypoints;

        current_pose = arm_move_group_interface.getCurrentPose().pose;
        target_pose = current_pose;
        target_pose.position.x = target_x;
        target_pose.position.y = target_y;
        target_pose.position.z = target_pose.position.z - 0.05;
        waypoints.push_back(target_pose);
        target_pose.position.z = target_pose.position.z - 0.065;
        waypoints.push_back(target_pose);
        moveit_msgs::msg::RobotTrajectory trajectory;
        const double jump_threshold = 0.0;
        const double eef_step = 0.001;
        arm_move_group_interface.computeCartesianPath(waypoints, eef_step, jump_threshold, trajectory);
        arm_move_group_interface.execute(trajectory);
        std::this_thread::sleep_for(2s);

        gripper_set(gripper_state, 1, logger);
        std::this_thread::sleep_for(5s);

        arm_move_group_interface.setNamedTarget("grip_ready");
        planAndExecute(arm_move_group_interface, plan, logger);
        std::this_thread::sleep_for(1s);

        arm_move_group_interface.setNamedTarget("home");
        planAndExecute(arm_move_group_interface, plan, logger);
        std::this_thread::sleep_for(2s);

        arm_move_group_interface.setNamedTarget("drop_ready");
        planAndExecute(arm_move_group_interface, plan, logger);
        std::this_thread::sleep_for(2s);

        gripper_set(gripper_state, 0, logger);
        std::this_thread::sleep_for(1s);

        arm_move_group_interface.setNamedTarget("home");
        planAndExecute(arm_move_group_interface, plan, logger);
        std::this_thread::sleep_for(2s);
    }
}

void handleServiceRequest(const std::shared_ptr<mycobot_interfaces::srv::StateRQ::Request> request, std::shared_ptr<mycobot_interfaces::srv::StateRQ::Response> response, moveit::planning_interface::MoveGroupInterface& arm_move_group_interface, moveit::planning_interface::MoveGroupInterface::Plan& plan, rclcpp::Logger service_logger ,rclcpp::Logger logger, rclcpp::Node::SharedPtr detection_request_node, rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr gripper_state) {
    if (request->trigger) {
        performTask(request->target, arm_move_group_interface, plan, logger, detection_request_node, gripper_state);
        response->endflag = false;
        response->result = 0;
        RCLCPP_INFO(service_logger, "task End");
    }
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto node = make_shared<rclcpp::Node>("grip_task_node", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
    auto const logger = rclcpp::get_logger("grip_task_node");
    rclcpp::executors::MultiThreadedExecutor executor;
    // rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);
    thread spinner = thread([&executor]() { executor.spin(); });

    // Cube detection node
    rclcpp::Node::SharedPtr detection_request_node = rclcpp::Node::make_shared("yolo_detection_service");

    using moveit::planning_interface::MoveGroupInterface;
    auto arm_move_group_interface = MoveGroupInterface(node, "mycobot_arm");
    auto hand_move_group_interface = MoveGroupInterface(node, "hand");
    moveit::planning_interface::MoveGroupInterface::Plan plan;
    geometry_msgs::msg::Quaternion quat_msg;

    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    auto objectname = planning_scene_interface.getKnownObjectNames();
    // for (auto& elem : objectname) cout << elem << " \n";
    planning_scene_interface.removeCollisionObjects(objectname);

    auto collision_object = addCollision(arm_move_group_interface);
    planning_scene_interface.applyCollisionObject(collision_object);
    auto gripper_state = node->create_publisher<std_msgs::msg::Int32>("gripper_state", 10);


    // Service
    auto task_service_node = make_shared<rclcpp::Node>("task_service_node", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));
    auto const task_service_logger = rclcpp::get_logger("task_service_node");
    auto service = task_service_node->create_service<mycobot_interfaces::srv::StateRQ>(
        "export_mycobot_state",
        [&](const std::shared_ptr<mycobot_interfaces::srv::StateRQ::Request> request,
            std::shared_ptr<mycobot_interfaces::srv::StateRQ::Response> response) {
            handleServiceRequest(request, response, arm_move_group_interface, plan, task_service_logger ,logger, detection_request_node, gripper_state);
        });

    rclcpp::spin(task_service_node);
    rclcpp::shutdown();
    spinner.join();

    return 0;
}