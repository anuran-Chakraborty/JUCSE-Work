import socket

portSend=12245
portRec=12395
frame_size=4

# Function to introduce error
def ins_error(frame, list_of_bit):

	new=list(frame)

	# Inserting error in the given bit position here
	for i in range(len(list_of_bit)):		
		if(new[list_of_bit[i]]=='0'):
			new[list_of_bit[i]]='1'
		elif (new[list_of_bit[i]]=='1'):
			new[list_of_bit[i]]='0'
	new=''.join(new)
	return new

# Function to create a socket and bind it to a port
def createSocket(port):
	s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind(('', port))
	return s

# Function to receive a connection
def allowConn(s):
	s.listen(5)
	c, addr=s.accept()
	return c, addr

# Function to create a socket and connect to it
def createConn(port):
	sock=socket.socket()
	sock.connect(('',port))
	return sock

# Function to send a frame
def send_frame(frame, c):
	# Send the frame to the other process
	c.send(frame.encode())