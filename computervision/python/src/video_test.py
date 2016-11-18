import numpy as np
import cv2
from opencv.video import create_capture

# Demo program to test if the webcam on your computer is working (should pop up a window with the webcam feed)

def get_cam_frame(cam):
    ret, img = cam.read()
    # smaller frame size - things run a lot smoother than a full screen img
    img = cv2.resize(img, (800, 450))
    return img

def main():
    # Camera 0 is usually the built in webcam camera... also most people only have 1 webcam on their laptop
    cam = create_capture(0)
    
    while True:
        img = get_cam_frame(cam)
        cv2.imshow('video test', img)
        # Esc key quits
        if 0xFF & cv2.waitKey(1) == 27:
            break
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()