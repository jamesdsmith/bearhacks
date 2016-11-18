import cv2

def get_camera_frame(camera):
    _, image = camera.read()
    image = cv2.resize(image, (800, 450))
    
    return image

def main():
    camera = cv2.VideoCapture(0)
    
    while True:
        img = get_camera_frame(camera)
        cv2.imshow('video test', img)
        
        if 0xFF and cv2.waitKey(1) == 27:
            break
        
    cv2.destroyAllWindows()
    
if __name__ == '__main__':
    main()