import socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # For UDP
udp_host = socket.gethostname() # Host IP
udp_port = 12345 # specified port to connect
# sock.sendto(b'req', (udp_host, udp_port))

while True:
    message = input('enter message: ')
    sock.sendto(message.encode(),(udp_host,udp_port))
    data = sock.recv(1024)
    print('server:', data.decode())