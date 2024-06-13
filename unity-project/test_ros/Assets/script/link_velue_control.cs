using UnityEngine;
using UnityEngine.UI;
using System.Collections.Generic;
using TMPro;
public class ArticulationBodyValuesDisplay : MonoBehaviour
{
    public GameObject parentObject;  //  오브젝트를 에디터에서 할당
    public TextMeshProUGUI[] uiText= new TextMeshProUGUI[6];  // UI 텍스트를 에디터에서 할당

    private List<ArticulationBody> Links = new List<ArticulationBody>();

    void Start()
    {
        if (parentObject != null)
        {
            // 재귀적으로 모든 ArticulationBody 찾기
            FindAllLinks(parentObject.transform);
        }
        else
        {
            Debug.LogError("Parent Object를 할당해주세요.");
        }

        foreach(var elem in Links){
            Debug.Log(elem.name);
        }
        // Debug.Log(Links);
    }

    void FindAllLinks(Transform parent)
    {
        foreach (Transform child in parent)
        {
            ArticulationBody articulationBody = child.GetComponent<ArticulationBody>();
            if (articulationBody != null)
            {
                if (articulationBody.name=="link1"||articulationBody.name=="link2"||articulationBody.name=="link3"||articulationBody.name=="link4"||articulationBody.name=="link5"||articulationBody.name=="link6")
                Links.Add(articulationBody);
            }
            
            // 재귀적으로 자식 노드를 탐색
            FindAllLinks(child);
        }
    }

    void Update()
    {
        if (Links.Count > 0)
        {
            string displayText = "";
            int cnt =0;
            foreach (var articulationBody in Links){
                float targetPosition = Mathf.Round(articulationBody.xDrive.target);
                // Vector3 targetVelocity = articulationBody.targetVelocity;
                displayText = $"{articulationBody.name} : {targetPosition}";
                uiText[cnt].text = displayText;
                cnt ++;
            }
            // Debug.Log(displayText);
            // uiText.text = displayText;
        }
    }
}
