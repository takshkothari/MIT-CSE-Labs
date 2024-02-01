import socket # Import socket module
host = socket.gethostname() # Get local machine name
port = 1112 # Reserve a port for your service.
s = socket.socket() # Create a socket object
s.bind((host, port)) # Bind to the port
s.listen(5) # Now wait for client connection.
conn, addr = s.accept() # Establish connection with client.
print('Got connection from', addr[0], '(', addr[1], ')')
print('Thank you for connecting')
while True:
    data = conn.recv(1024)
    if not data: break
    conn.sendall(data)
    print('Received message is sent back to client')
conn.close() # Close the connection