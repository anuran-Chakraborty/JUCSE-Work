import socket
import time
import common as co
import random
import errorchecker as err
import threading

# Check if ack is valid using crc
def isValid(ack):
	# Now check CRC
	if(int(err.modulo2div(ack,err.generator_poly),2)!=0):
		return False
	return True

# Function to send list of frames
def sendFrame(list_of_frames):
	global sn
	i=0
	while i<len(list_of_frames):
		# Store_frame(sn)
		stored_frame=list_of_frames[i]

		if(stored_frame!='#'):
			stored_frame=co.prepare_frame_gbn(list_of_frames[i],sn)
		# Else send the blank frame
		# If window size reached wait
		if(sn-sf<sw):
			# Sendframe(sn)
			print('Sending frame '+str(i)+' '+stored_frame)
			co.send_frame(stored_frame, sender)
			sn=sn+1
			i=i+1
		time.sleep(1)

# Function to receive ack
def receiveFrame():
	global sf
	resendThread=threading.Thread(target=resendFrameAfterTimeout, args=(list_of_frames,)) # create the sending thread
	while True:

		try:
			ack=sockRec.recv(1024).decode()
		except Exception as e:
			# Resend so repeat this iteration of loop
			print('Timeout.. Resending')
			resendThread.start()
			resendThread.join()

		print('Ack received '+str((ack[0:3])))
		if(ack !='#' and isValid(ack)): # Correct acknowledgement 
			print('Correct ack received')
			ackno=int(ack[:-(len(err.generator_poly)-1)],2)
			# Purge required frames
			if(ackno>sf and ackno<=sn):
				while(sf<=ackno):
					print('Deleting frame '+str(sf))
					sf=sf+1

		elif(ack !='#' and not isValid(ack,sn)): # Wrong ack
			# invalid ack so resend
			print('Wrong ack.. resending')

		elif(ack=='#'):
			break

# Function to resend frame after timeout
def resendFrameAfterTimeout(list_of_frames):
	global sn
	global sf

	# Resend frame
	temp=sf

	while(temp<sf):
		print('Resending frame '+str(temp)+' '+stored_frame)
		co.send_frame(list_of_frames[temp], sender)
		temp=temp+1

# Function to send all the frames
def send_all(list_of_frames):
	
	sendThread=threading.Thread(target=sendFrame, args=(list_of_frames,)) # create the sending thread
	receiveThread=threading.Thread(target=receiveFrame) # create the receiving thread

	sendThread.start()
	receiveThread.start()


	sendThread.join()
	print('Send thread end')
	receiveThread.join()

	# Close the sockets
	sockSend.close()
	sockRec.close()

timeoutTime=100
frame_size=4
sw=2**co.m-1
sf=0
sn=0

print('Demonstrating Go Back N ARQ')
list_of_frames=co.readfile('input.txt', frame_size)
print(list_of_frames)
list_of_frames.append('#') # Attach a blank frame

sockSend=co.createSocket(co.portSenderSend) # sender socket to send data to channel
sender, addr=co.allowConn(sockSend)

sockRec=co.createConn(co.portSenderReceive)	# Socket to receive data from channel
sockRec.settimeout(timeoutTime)

print('Connected to channel')

send_all(list_of_frames)