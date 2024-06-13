using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using JointState = RosMessageTypes.Sensor.JointStateMsg;
using System.Collections;
 
public class JointStateSub : MonoBehaviour
{
    [SerializeField] private string rosTopic = "joint_states";
    [SerializeField] private ROSConnection ROS;
    [SerializeField] private ArticulationBody[] robotJoints = new ArticulationBody[8];

    [SerializeField] private ArticulationBody[] r_hand = new ArticulationBody[3];
    [SerializeField] private ArticulationBody[] l_hand = new ArticulationBody[3];

    
    // Start is called before the first frame update

    void Start()
    {
        ROS = ROSConnection.GetOrCreateInstance();
        ROS.Subscribe<JointState>(rosTopic, GetJointPositions);
    }

 
    private void GetJointPositions(JointState sensorMsg)
    {
        StartCoroutine(SetJointValues(sensorMsg));
    }
    IEnumerator SetJointValues(JointState message)
    {
        for (int i = 0; i < message.name.Length; i++)
        {   
            if (i==6){
                for (int j =0; j<r_hand.Length;j++){
                    var r_handXDrive = r_hand[j].xDrive;
                    var l_handXDrive = l_hand[j].xDrive;
                    r_handXDrive.target = -(float)(message.position[i]) * Mathf.Rad2Deg;
                    l_handXDrive.target = (float)(message.position[i]) * Mathf.Rad2Deg;
                    r_hand[j].xDrive = r_handXDrive;
                    l_hand[j].xDrive = l_handXDrive;
                }
            }
            var joint1XDrive = robotJoints[i].xDrive;
            joint1XDrive.target = (float)(message.position[i]) * Mathf.Rad2Deg;
            robotJoints[i].xDrive = joint1XDrive;
            // Debug.Log(joint1XDrive.target);
            
        }
 
        yield return new WaitForSeconds(0.5f);
    }
 
    public void UnSub()
    {
        ROS.Unsubscribe(rosTopic);
    }
}