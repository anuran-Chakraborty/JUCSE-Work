import socket
import common as co
import time
import random
import errorchecker as err

probas=10
rand=0

# Function to check if frame is valid
def isValid(frame, rn):
	if(frame[0]!=str(rn)):
		return False
	# Now check CRC
	if(int(err.modulo2div(frame,err.generator_poly),2)!=0):
		return False
	return True

def receive():
	# Establish connection
	sockSend=co.createConn(co.portSend)
	print('Connected to sender')
	sockRec=co.createSocket(co.portRec)
	c, addr=co.allowConn(sockRec)

	
	# Connection established
	rn=0
	while True:
		# Wait till frame received
		print(12*'-')
		frame=sockSend.recv(1024).decode()
		
		print('Frame received '+frame)

		if(not isValid(frame, rn)): # skip the iteration
			print('Invalid frame')
			continue

		# For valid data frame
		rn=(rn+1)%2
		# Send an acknowledgement
		ack=co.generateAck(rn)
		# Add sleep here
		time.sleep(3)
		# send the frame with a probability
		p=random.randint(0,probas)
		print(p)
		if(p>=rand):
			print('Sending ack '+ack)
			co.send_frame(ack,c)
		else:
			print('Not sending acknowledgement')

		if(frame=='100100'):
			break
		print(12*'-')

	# Close the sockets
	sockSend.close()
	sockRec.close()

print('Demonstrating GO BACK N ARQ')
receive()