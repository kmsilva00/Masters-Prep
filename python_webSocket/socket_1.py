import socket
import sys

PORT = 80

#try to create socket
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
except socket.error as e:
    print("error in creation of socket %s" %e)


#try to get ip by hostname
try:
    host_ip = socket.gethostbyname("www.google.com")

except socket.gaierror:
    print("error resolving host")
    sys.exit()
#connect

s.connect((host_ip,PORT))
print("socket connected to google")
