import socket
import time
import common as co
import random
import errorchecker as err

timeoutTime=5
frame_size=4
probas=10
rand=0

# Check if ack is valid using crc
def isValid(ack,sn):

	if(ack[0]!=str((sn+1)%2)):
		return False
	# Now check CRC
	if(int(err.modulo2div(ack,err.generator_poly),2)!=0):
		return False
	return True

# Function to send all the frames
def send_all(list_of_frames):
	sockSend=co.createSocket(co.portSend) # sender socket
	c, addr=co.allowConn(sockSend)

	sockRec=co.createConn(co.portRec)
	sockRec.settimeout(timeoutTime)

	print('Connected to recevier')
	# implementing stop and wait arq
	sn=0
	i=0
	while(i<(len(list_of_frames))): # While there are frames send
		print(12*'-')
		canSend=True
		sn=(i)%2
		stored_frame=co.prepare_frame(list_of_frames[i],sn)

		# Send frame with a probability p
		p=random.randint(0,probas)
		print(p)
		if(p>=rand and i<len(list_of_frames)-1):
			print('Sending frame '+str(i)+' '+stored_frame)
			
			# Introduce error here with a probability
			p=random.randint(0,probas)
			if(p<=4 and i<len(list_of_frames)-1):
				print("Introducing error")
				stored_frame=co.ins_error(stored_frame,[0])
				print('Sent frame '+stored_frame)

			# Add sleep here
			time.sleep(3)
			# Send the frame
			co.send_frame(stored_frame, c)		
			canSend=False
		else:
			print('Not sending frame')

		try:
			ack=sockRec.recv(1024).decode()
		except Exception as e:
			# Resend so repeat this iteration of loop
			print('Timeout.. Resending')
			continue
	
		print('Ack received '+ack)
		if(ack and isValid(ack,sn)): # Wrong acknowledgement 
			print('Correct ack received')
			canSend=True
			i=i+1
		elif(not isValid(ack,sn)):
			# invalid ack so resend
			print('Wrong ack.. resending')

		print(12*'-')

	# Close the sockets
	sockSend.close()
	sockRec.close()

print('Demonstrating GO BACK N ARQ')
list_of_frames=co.readfile('input.txt', frame_size)
send_all(list_of_frames)