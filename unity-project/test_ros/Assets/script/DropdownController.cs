using UnityEngine;
using UnityEngine.UI;
using Cinemachine;
using TMPro;

public class CameraSwitcher : MonoBehaviour
{
    public TMP_Dropdown cameraDropdown;
    public CinemachineFreeLook[] freeLookCameras;
    private int defaultPriority = 10;
    private int selectedPriority = 20;
    private Vector3[] originalPositions;
    private Vector3[] originalRotations;

    void Start()
    {
        originalPositions = new Vector3[freeLookCameras.Length];
        originalRotations = new Vector3[freeLookCameras.Length];

        // 초기 위치와 회전값 저장
        for (int i = 0; i < freeLookCameras.Length; i++)
        {
            originalPositions[i] = freeLookCameras[i].transform.position;
            originalRotations[i] = freeLookCameras[i].transform.eulerAngles;
        }

        cameraDropdown.onValueChanged.AddListener(delegate {
            SwitchCamera(cameraDropdown.value);
        });
        // 초기 상태 설정
        SwitchCamera(cameraDropdown.value);
    }

    void SwitchCamera(int index)
    {
        for (int i = 0; i < freeLookCameras.Length; i++)
        {
            if (i == index)
            {
                freeLookCameras[i].Priority = selectedPriority;
            }
            else
            {
                freeLookCameras[i].Priority = defaultPriority;
                ResetCamera(i);
            }
        }
    }

    void ResetCamera(int index)
    {
        freeLookCameras[index].transform.position = originalPositions[index];
        freeLookCameras[index].transform.eulerAngles = originalRotations[index];
    }
}
