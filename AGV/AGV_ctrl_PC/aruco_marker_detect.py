import cv2
import numpy as np
import yaml
import argparse
from socket_video_server import VideoStreamServer 

def detect_markers(image, camera_matrix, dist_coeffs, marker_size):
    aruco_dict = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_6X6_1000)
    parameters = cv2.aruco.DetectorParameters()
    detector = cv2.aruco.ArucoDetector(aruco_dict, parameters)
    corners, ids, _ = detector.detectMarkers(image)
    detect_data = []
    if ids is not None:
        cv2.aruco.drawDetectedMarkers(image, corners, ids)
        rvecs, tvecs, _ = my_estimatePoseSingleMarkers(corners, marker_size, camera_matrix, dist_coeffs)
        
        if rvecs is not None and tvecs is not None:
            for rvec, tvec, marker_id in zip(rvecs, tvecs, ids):
                rot_mat, _ = cv2.Rodrigues(rvec)
                yaw, pitch, roll = rotationMatrixToEulerAngles(rot_mat)
                marker_pos = np.dot(-rot_mat.T, tvec).flatten()
                # Calculate distance from the camera to the marker
                distance = np.linalg.norm(tvec)
                # print(f"Marker ID: {marker_id}, Position: {marker_pos}, Angles: (Yaw: {yaw}, Pitch: {pitch}, Roll: {roll}), Distance: {distance:.2f}m")
                frame_x=int((corners[0][0][0][0]+corners[0][0][1][0])/4 + (corners[0][0][2][0]+corners[0][0][3][0])/4)
                frame_y=int((corners[0][0][1][1]+corners[0][0][2][1])/4 + (corners[0][0][0][1]+corners[0][0][3][1])/4)
                detect_data.append([marker_id, marker_pos, (yaw, pitch, roll), distance,(frame_x,frame_y)])
                cv2.drawFrameAxes(image, camera_matrix, dist_coeffs, rvec, tvec, marker_size / 2)
        
    else:
        # print("No markers detected")
        pass
    return image, detect_data

def my_estimatePoseSingleMarkers(corners, marker_size, mtx, distortion):
    marker_points = np.array([[-marker_size / 2, marker_size / 2, 0],
                              [marker_size / 2, marker_size / 2, 0],
                              [marker_size / 2, -marker_size / 2, 0],
                              [-marker_size / 2, -marker_size / 2, 0]], dtype=np.float32)
    rvecs = []
    tvecs = []
    for c in corners:
        _, R, t = cv2.solvePnP(marker_points, c, mtx, distortion, False, cv2.SOLVEPNP_IPPE_SQUARE)
        rvecs.append(R)
        tvecs.append(t)
    return rvecs, tvecs, []

def rotationMatrixToEulerAngles(R):
    sy = np.sqrt(R[0,0] * R[0,0] + R[1,0] * R[1,0])
    singular = sy < 1e-6
    if not singular:
        x = np.arctan2(R[2,1], R[2,2])
        y = np.arctan2(-R[2,0], sy)
        z = np.arctan2(R[1,0], R[0,0])
    else:
        x = np.arctan2(-R[1,2], R[1,1])
        y = np.arctan2(-R[2,0], sy)
        z = 0
    return np.degrees(x), np.degrees(y), np.degrees(z)

def load_camera_parameters(yaml_file):
    with open(yaml_file, 'r') as f:
        data = yaml.safe_load(f)
        camera_matrix = np.array(data["camera_matrix"]["data"], dtype=np.float32).reshape(3, 3)
        dist_coeffs = np.array(data["distortion_coefficients"]["data"], dtype=np.float32)
    return camera_matrix, dist_coeffs

def main(marker_size=0.105, frame=np.array([0])):
    VS=VideoStreamServer(port=8064)
    VS.cam_ui=True
    VS.accept_connection()
    camera_matrix, dist_coeffs = load_camera_parameters('/home/park/Downloads/AGVP3/calibration_params.yaml')
    while True:
        VS.getframe()
        frame, detect_data = detect_markers(VS.frame, camera_matrix, dist_coeffs, marker_size)
        print(detect_data)
        cv2.imshow('Detected Markers', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cv2.destroyAllWindows()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Detect ArUco markers.')
    parser.add_argument('--marker_size', type=float, default=0.105,
                        help='Size of the ArUco markers in meters.')
    args = parser.parse_args()
    main(args.marker_size)
