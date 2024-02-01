# Write a UDP simple chat program for message send and receive.

import socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # For UDP
udp_host = socket.gethostname() # Host IP
udp_port = 12345 # specified port to connect
sock.bind((udp_host, udp_port))
while True:
    data, addr = sock.recvfrom(1024)
    print('client:', data.decode())
    message = input('enter message: ')
    sock.sendto(message.encode(),addr)