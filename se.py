import cv2
import numpy as np
import socket
import sys 
#127.0.0.1 5090 0 50
skt  = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

cap=cv2.VideoCapture(int( sys.argv[3]) )

while True:
	ret,frame=cap.read()

	img_encode = cv2.imencode('.jpg', frame,[int(cv2.IMWRITE_JPEG_QUALITY), int( sys.argv[4] )] )[1]

	str_encode = np.array(img_encode).tostring()
	nparr = np.fromstring(str_encode, np.uint8)

	skt.sendto(img_encode,(sys.argv[1],int( sys.argv[2] ) ) )

	cv2.waitKey(1)


cap.release()
cv2.destroyAllWindows()
