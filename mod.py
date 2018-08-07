import cv2
import numpy as np
import serial
import time



usbport = 'COM7'

ser = serial.Serial(usbport, 9600, timeout=1)


def move(servo, angle):


    if (-180<= angle <= 180):
        ser.write(chr(255))
        ser.write(chr(servo))
        ser.write(chr(angle))
    else:
        print("Servo angle must be an integer between 0 and 180.\n")
   
WINDOW_NAME = 'Electronics Project ' 

def track(image):



    blur = cv2.GaussianBlur(image, (5,5),0)

    hsv = cv2.cvtColor(blur, cv2.COLOR_BGR2HSV)

    lower_green = np.array([40,70,70])
    upper_green = np.array([80,200,200])

    mask = cv2.inRange(hsv, lower_green, upper_green)
    
    bmask = cv2.GaussianBlur(mask, (5,5),0)

    moments = cv2.moments(bmask)
    m00 = moments['m00']
    centroid_x, centroid_y = 0, 0
    if m00 != 0:
        centroid_x = int(moments['m10']/m00)
        centroid_y = int(moments['m01']/m00)

    ctr = (-1,-1)

    if centroid_x != 0 and centroid_y != 0:

        ctr = (centroid_x  , centroid_y)
    
        cv2.circle(image, ctr, 4, (0,0,0))

    cv2.imshow(WINDOW_NAME, image)

    if cv2.waitKey(1) & 0xFF == 27:
        ctr = 0
    
    print ctr
    dd=1
    while(dd>0):
        if(centroid_x>200 and centroid_x<400 ): 
               
            move(1,11)
            print"Object detected"
            #time.sleep(1)
            dd=0
        
            
        elif(centroid_x<=200 and centroid_x>0):
            print "Object at left side"           
            move(1,10)
            #time.sleep(1)
            dd=0
            
        elif(centroid_x>=400 and centroid_x<=700):
            print "Object at right side"
            move(1,20)
            #time.sleep(1)
            dd=0
        else:
            move(1,30)
            print "Object is not in camera's range" 
            dd=0

    return ctr
if __name__ == '__main__':
    #move(1,90)
    capture = cv2.VideoCapture(1)
   
    while True:

        okay, image = capture.read()
    
        if okay:
        #print ctr

            if not track(image):
                break
          
            if cv2.waitKey(1) & 0xFF == 27:
                break

        else:

           print('Capture failed')
           break
