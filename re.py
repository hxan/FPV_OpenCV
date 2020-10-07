




import socket
import cv2
import numpy as np
import time
import sys 

BUFSIZE = 102400
ip_port = ('127.0.0.1', int(sys.argv[1]) )
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
server.bind(ip_port)

while True:
    img_encode,client_addr = server.recvfrom(BUFSIZE)
    str_encode = np.array(img_encode).tostring()
    nparr = np.fromstring(str_encode, np.uint8)
    img_decode = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
    cv2.imshow("img_decode", img_decode)
    cv2.waitKey(1)   

server.close()
