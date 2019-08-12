import socket

portServer=12345

# Function to create a socket and bind it to a port
def createSocket(port):
	s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
	s.bind(('', port))
	return s

# Function to receive a connection
def allowConn(s):
	s.listen(5)
	c, addr=s.accept()
	return c, addr

# Function to create a socket and connect to it
def createConn(port,ip=''):
	sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect((ip,port))
	return sock

# Function to send a frame
def send_frame(frame, c):
	# Send the frame to the other process
	c.send(frame.encode())