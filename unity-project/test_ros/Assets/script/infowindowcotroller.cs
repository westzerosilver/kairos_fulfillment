using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class InfoWindowController : MonoBehaviour
{
    public GameObject infoWindow; // 정보 창 Panel을 연결

    void Start()
    {
        infoWindow.SetActive(false); // 시작 시 정보 창 비활성화

    }
    void Update(){
        if (Input.GetMouseButtonDown(1)){
            HideInfoWindow();
        }
    }

    public void ShowInfoWindow()
    {
        infoWindow.SetActive(true); // 정보 창 활성화
    }

    public void HideInfoWindow()
    {
        infoWindow.SetActive(false); // 정보 창 비활성화
    }
}
