using UnityEngine;

public class RaycastClickLogger : MonoBehaviour
{

    public GameObject ExportMycobotinfoWindow;
    public GameObject ImportMycobotinfoWindow;

    void Update()
    {
        // 마우스 왼쪽 버튼이 클릭된 경우
        if (Input.GetMouseButtonDown(0))
        {
            // 메인 카메라에서 마우스 위치로 레이 생성
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;

            // 레이가 오브젝트와 충돌했는지 확인
            if (Physics.Raycast(ray, out hit))
            {
                // 충돌한 오브젝트의 정보를 로깅
                GameObject clickedObject = hit.collider.gameObject;
                string topmostParentName = GetTopmostParentName(clickedObject);

                // Debug.Log("Clicked on object: " + clickedObject.name);
                // Debug.Log("Object position: " + clickedObject.transform.position);
                Debug.Log("Clicked on object: " + topmostParentName);

                if (topmostParentName == "mycobot_320_export") ExportMycobotinfoWindow.SetActive(true);
                else if(topmostParentName =="mycobot_320_import") ImportMycobotinfoWindow.SetActive(true);
            }
        }
    }

    string GetTopmostParentName(GameObject obj)
    {
        // 현재 오브젝트가 최상위 부모인지 확인
        while (obj.transform.parent != null)
        {
            obj = obj.transform.parent.gameObject;
        }
        return obj.name;
    }
}
