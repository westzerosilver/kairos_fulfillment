using UnityEngine;
using UnityEngine.UI;
using Unity.Robotics.ROSTCPConnector;
using RosMessageTypes.Sensor;
using System.Collections;
using System.Collections.Generic;

public class ImageSubscriber : MonoBehaviour
{
    [SerializeField] private string rosTopic = "camera/image";
    [SerializeField] private ROSConnection rosConnection;
    [SerializeField] private RawImage rawImage;
    
    private Texture2D texture2D;
    private bool isMessageReceived;
    private Queue<ImageMsg> messageQueue = new Queue<ImageMsg>();

    private void Start()
    {
        if (rosConnection == null)
        {
            rosConnection = ROSConnection.GetOrCreateInstance();
        }
        rosConnection.Subscribe<ImageMsg>(rosTopic, QueueImage);
        
        // Initialize the Texture2D with a dummy size, it will be resized later
        texture2D = new Texture2D(2, 2, TextureFormat.RGB24, false);
        rawImage.texture = texture2D;
    }

    private void Update()
    {
        if (isMessageReceived && messageQueue.Count > 0)
        {
            ProcessImage();
            isMessageReceived = false;
        }
    }

    private void QueueImage(ImageMsg imageMessage)
    {
        // If the GameObject is not active, do not queue the message
        if (!gameObject.activeInHierarchy)
        {
            // Debug.Log("ImageReceiver is inactive, discarding image message.");
            if(messageQueue.Count != 0){
                messageQueue.Clear();
                // Debug.Log("Queue empty");
            }
            return;
        }

        messageQueue.Enqueue(imageMessage);
        isMessageReceived = true;
    }

    private void ProcessImage()
    {
        if (messageQueue.Count > 0)
        {
            var imageMessage = messageQueue.Dequeue();
            StartCoroutine(UpdateTexture(imageMessage));
        }
    }

    private IEnumerator UpdateTexture(ImageMsg imageMessage)
    {
        // Ensure the texture size matches the image message
        int width = (int)imageMessage.width;
        int height = (int)imageMessage.height;
        int dataLength = width * height * 3;  // Assuming BGR8 format (3 bytes per pixel)

        if (imageMessage.data.Length != dataLength)
        {
            Debug.LogError($"Image data length mismatch: expected {dataLength}, but got {imageMessage.data.Length}");
            yield break;
        }

        if (texture2D.width != width || texture2D.height != height)
        {
            texture2D.Reinitialize(width, height);
        }

        // Convert BGR8 to RGB24 and flip Y-axis
        byte[] rgbData = new byte[dataLength];
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int srcIndex = (y * width + x) * 3;
                int dstIndex = ((height - 1 - y) * width + x) * 3;
                rgbData[dstIndex] = imageMessage.data[srcIndex + 2]; // R
                rgbData[dstIndex + 1] = imageMessage.data[srcIndex + 1]; // G
                rgbData[dstIndex + 2] = imageMessage.data[srcIndex]; // B
            }
        }

        // Load the converted RGB data into the texture
        texture2D.LoadRawTextureData(rgbData);
        texture2D.Apply();

        rawImage.texture = texture2D;
        yield return null;
    }

    public void Unsubscribe()
    {
        rosConnection.Unsubscribe(rosTopic);
    }
}
