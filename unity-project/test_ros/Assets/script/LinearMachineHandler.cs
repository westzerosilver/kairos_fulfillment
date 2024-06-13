using UnityEngine;
using Unity.Robotics.ROSTCPConnector;
using String = RosMessageTypes.Std.StringMsg;
using System.Collections;
using System;
using System.Text.RegularExpressions;

public class LMStateSub : MonoBehaviour
{
    [SerializeField] private string rosTopic = "liner_machine_state";
    [SerializeField] private ROSConnection ROS;
    [SerializeField] private ArticulationBody Xaxis;
    [SerializeField] private ArticulationBody Yaxis;
    [SerializeField] private GameObject[] box = new GameObject[8];

    [SerializeField] private float[] x_offset=new float[3];
    // x_offset={0.0, 0.0, 0.0};
    [SerializeField] private float[] y_offset=new float[3];
    // y_offset=[0.0, 0.0, 0.0];    
    // Start is called before the first frame update
    // private bool isMoving = false;
    void Start()
    {
        ROS = ROSConnection.GetOrCreateInstance();
        ROS.Subscribe<String>(rosTopic, GetLinearState);
        // box[7].SetActive(false);
        // box[6].SetActive(false);
    }

 
    private void GetLinearState(String stateMsg)
    {
        StartCoroutine(SetLinearState(stateMsg));
    }

    private bool is_out;
    private int x ;
    private int y ;

    IEnumerator SetLinearState(String message)
    {   
       
       
       
        if(message.data=="out0,0"){
            is_out = true; x=0; y=0;
        }else if(message.data=="out1,0"){
            is_out = true; x=1; y=0;
        }else if(message.data=="out2,0"){
            is_out = true; x=2; y=0;
        }else if(message.data=="out0,1"){
            is_out = true; x=0; y=1;
        }else if(message.data=="out1,1"){
            is_out = true; x=1; y=1;
        }else if(message.data=="out2,1"){
            is_out = true; x=2; y=1;
        }
        else if(message.data=="out0,0"){
            is_out = false; x=0; y=0;
        }else if(message.data=="in1,0"){
            is_out = false; x=1; y=0;
        }else if(message.data=="in2,0"){
            is_out = false; x=2; y=0;
        }else if(message.data=="in0,1"){
            is_out = false; x=0; y=1;
        }else if(message.data=="in1,1"){
            is_out = false; x=1; y=1;
        }else if(message.data=="in2,1"){
            is_out = false; x=2; y=1;
        }
        if(is_out){

            set_target(x_offset[x],y_offset[y]);
            yield return new WaitForSecondsRealtime(8.0f);
            // box[x+y*3].SetActive(false);
            // box[6].SetActive(true);
            set_target(x_offset[2],y_offset[2]);
            yield return new WaitForSecondsRealtime(8.0f);
            // box[6].SetActive(false);
            // box[7].SetActive(true);
            set_target(x_offset[0],y_offset[0]);
            yield return new WaitForSecondsRealtime(10.0f);
            // box[6].SetActive(false);
        }else{
            // box[7].SetActive(true);
            // box[x+y*3].SetActive(false);
            set_target(x_offset[2],y_offset[2]);
            yield return new WaitForSecondsRealtime(10.0f);
            // box[7].SetActive(false);
            // box[6].SetActive(true);
            set_target(x_offset[x],y_offset[y]);
            yield return new WaitForSecondsRealtime(8.0f);
            // box[7].SetActive(false);
            // box[x+y*3].SetActive(true);
            set_target(x_offset[0],y_offset[0]);
            yield return new WaitForSecondsRealtime(8.0f);
            // box[6].SetActive(false);
        }
        
        
        yield return new WaitForSeconds(0.5f);
    }


    public void set_target(float x,float y){
        var XaxisDrive = Xaxis.xDrive;
        var YaxisDrive = Yaxis.xDrive;
        XaxisDrive.target=x;
        YaxisDrive.target=y;
        Xaxis.xDrive = XaxisDrive;
        Yaxis.xDrive = YaxisDrive;
        
    }
 
    public void UnSub()
    {
        ROS.Unsubscribe(rosTopic);
    }
}