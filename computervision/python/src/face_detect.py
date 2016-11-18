import numpy as np
import cv2
from opencv.video import create_capture

# Use a classifier to detect a face in the video frame

def get_cam_frame(cam):
    ret, img = cam.read()
    # smaller frame size - things run a lot smoother than a full screen img
    img = cv2.resize(img, (800, 450))
    return img

def detect(img, cascade):
    rects = cascade.detectMultiScale(img, scaleFactor=1.3, minNeighbors=4, minSize=(30, 30), flags=cv2.CASCADE_SCALE_IMAGE)
    if len(rects) == 0:
        return []
    rects[:,2:] += rects[:,:2]
    return rects

def main():
    # Camera 0 is usually the built in webcam camera... also most people only have 1 webcam on their laptop
    cam = create_capture(0)

    cascade = cv2.CascadeClassifier("../data/haarcascade_frontalface_default.xml")

    while True:
        img = get_cam_frame(cam)

        # classifier wants things in black and white
        bw = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        bw = cv2.equalizeHist(bw)

        rects = detect(bw, cascade)

        # Mostly useful for debugging
        for x1, y1, x2, y2 in rects:
            cv2.rectangle(img, (x1, y1), (x2, y2), (0,255,0), 2)

        cv2.imshow('face detect', img)

        # Esc key quits
        if 0xFF & cv2.waitKey(1) == 27:
            break
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()