#  Write a UDP time server to display the current time and day

import socket
import datetime
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # For UDP
udp_host = socket.gethostname() # Host IP
udp_port = 12345 # specified port to connect
sock.bind((udp_host, udp_port))
while True:
    data, addr = sock.recvfrom(1024)
    #receive data from client
    if not data: break
    print("sent msg to client")
    current_time = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    sock.sendto(current_time.encode(), addr)