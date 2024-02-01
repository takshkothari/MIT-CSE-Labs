import socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # For UDP
udp_host = socket.gethostname() # Host IP
udp_port = 12345 # specified port to connect
sock.sendto(b'req', (udp_host, udp_port))
response, _ = sock.recvfrom(1024)
print('time and day:', response.decode())