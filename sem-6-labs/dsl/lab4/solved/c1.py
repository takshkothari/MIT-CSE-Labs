import socket # Import socket module
host = socket.gethostname() # Get local machine name
port = 1112 # Reserve a port for your service.
s = socket.socket() # Create a socket object
s.connect((host, port))
s.sendall(b'Welcome user!')
print('Client is connected to server and it has sent the message to server')
data = s.recv(1024)
print('This is printing the message received back by the server')
print(repr(data))
s.close() # Close the socket when done