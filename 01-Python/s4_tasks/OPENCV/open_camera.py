import cv2

def main():
    cam = cv2.VideoCapture(0)
    if not cam.isOpened():
        print("Unable to open camera.")
        return

    image_name = "camera1"

    while True:
        ret,frame = cam.read()

        if not ret:
            print("cannot open frame.")
            return
        
        cv2.imshow(image_name,frame)


        cam_val = cv2.waitKey(1)

        if cam_val == ord('c'):
            cv2.imwrite("usef.jpg",frame)
            print("Image is captured successfully...;)")
        if cam_val == ord('q'):
            break

    cam.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()
