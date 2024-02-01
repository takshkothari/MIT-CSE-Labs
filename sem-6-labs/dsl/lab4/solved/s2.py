import socket
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM) # For UDP
udp_host = socket.gethostname() # Host IP
udp_port = 12345 # specified port to connect
sock.bind((udp_host, udp_port))
while True:
    print('Waiting for client...')
    data,addr = sock.recvfrom(1024) #receive data from client
    if not data: break
    print('Received Messages:',data.decode(),'from',addr)
sock.close()