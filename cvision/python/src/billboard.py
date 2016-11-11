import numpy as np
import cv2
from opencv.video import create_capture

# Takes an image from the user's webcam and transforms it to be the same shape as a billboard on times square.

def get_cam_frame(cam):
    ret, img = cam.read()
    # smaller frame size - things run a lot smoother than a full screen img
    img = cv2.resize(img, (800, 450))
    return img

def main():
    # Camera 0 is usually the built in webcam camera... also most people only have 1 webcam on their laptop
    cam = create_capture(0)
    
    # Background image of times square. Shrink it down a little because it runs faster
    background = cv2.imread("../data/times_square.jpg")
    #background = cv2.resize(background, (800, 500))

    # get a sample camera frame
    img = get_cam_frame(cam)

    # The corners of the billboard that we want to replace in the times square image
    dest = np.array([[581,149], [766,101], [772,324], [585,328]], np.float32)
    src = np.array([[0,0], [img.shape[1],0], [img.shape[1], img.shape[0]], [0, img.shape[0]]], np.float32)
    # Create a transformation matrix that converts between the two coordinate systems
    tform = cv2.getPerspectiveTransform(src, dest)

    # Create a white image the size of our webcam frame so we can build a mask out of the transform we just made
    white = np.ones(img.shape, np.uint8)
    mask = (cv2.warpPerspective(white, tform, (background.shape[1], background.shape[0])) != 0)

    while True:
        img = get_cam_frame(cam)

        # Warp the webcam image to the shape we defined above (should be the shape of one of the billboards)
        warped = np.zeros(background.shape, np.uint8)
        warped = cv2.warpPerspective(img, tform, (background.shape[1], background.shape[0]))

        # make a copy of the background... we could keep copying over the same image technically (possible optimization)
        final = background.copy()
        final[mask] = warped[mask]

        cv2.imshow('billboard', final)

        # Esc key quits
        if 0xFF & cv2.waitKey(1) == 27:
            break
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()