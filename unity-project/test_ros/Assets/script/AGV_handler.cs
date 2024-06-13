using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using Int8 = RosMessageTypes.Std.Int8Msg;
using System.Collections;
 
public class AGVStateSub : MonoBehaviour
{
    [SerializeField] private string rosTopic = "import/agv_state";
    [SerializeField] private ROSConnection ROS;
    [SerializeField] private GameObject[] Agvlist = new GameObject[3];

    
    // Start is called before the first frGame

    void Start()
    {
        ROS = ROSConnection.GetOrCreateInstance();
        ROS.Subscribe<Int8>(rosTopic, GetAGVState);
    }

 
    private void GetAGVState(Int8 stateMsg)
    {
        StartCoroutine(SetStateValues(stateMsg));
    }
    IEnumerator SetStateValues(Int8 stateMsg)
    {
        if(stateMsg.data==0){
            // Debug.Log("agv state : 0");
            Agvlist[0].SetActive(true);
            Agvlist[1].SetActive(false);
            Agvlist[2].SetActive(false);
        }
        else if(stateMsg.data==1){
            // Debug.Log("agv state : 1");
            Agvlist[1].SetActive(true);
            Agvlist[0].SetActive(false);
            Agvlist[2].SetActive(false);
        }
        else if(stateMsg.data==2){

            // Debug.Log("agv state : 2");
            Agvlist[2].SetActive(true);
            Agvlist[1].SetActive(false);
            Agvlist[0].SetActive(false);
        }

        yield return new WaitForSeconds(0.5f);
    }
 
    public void UnSub()
    {
        ROS.Unsubscribe(rosTopic);
    }
}