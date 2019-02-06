import socket
import common as co
import time
import random
import errorchecker as err


# Function to check if frame is valid
def isValid(frame, rn):
	if(int(err.modulo2div(frame,err.generator_poly),2)!=0):
		return False
	return True

def receive():
	# Establish connection
	sockRec=co.createSocket(co.portReceiverSend)
	c, addr=co.allowConn(sockRec)

	sockSend=co.createConn(co.portReceiverReceive)
	print('Connected to channel')
	
	# Connection established
	rn=0
	while True:
		# Wait till frame received
		print(15*'-')
		frame=sockSend.recv(1024).decode()
		
		print('Frame received '+frame)

		if(frame!='#' and not isValid(frame, rn)): # wrong frame no received send ack for prev
			print('Invalid frame')
		if(frame!='#'):
			ackno=frame[0:3]
			# Send an acknowledgement
			ack=co.generateAck_gbn(ackno)
		else:
			ack='#'

		time.sleep(1)
		# Send the ack
		print('Sending ack '+ack)
		co.send_frame(ack,c)

		print(15*'-')
		if(frame=='#'): # Means end frame
			break	

	# Close the sockets
	sockSend.close()
	sockRec.close()

print('Demonstrating Go Back N ARQ')
receive()