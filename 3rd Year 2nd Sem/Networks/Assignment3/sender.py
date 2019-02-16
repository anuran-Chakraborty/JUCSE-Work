import common as co
import time
import socket
import random
import time
import threading

isBusyChannel=0
sockSend=co.createConn(co.portSenderReceive)	# Socket to send data to channel
print('Connected to channel')

probab=10
p=4
timeSlot=2

# Function to send frames
def send_frame(list_of_frames):

	i=0
	while(i<len(list_of_frames)):
		# Sense the channel and check if flag is 1 then dont send
		if(isBusyChannel==0): # Channel is free
			# Send the frame with a probability p
			pr=random.randint(0,probab)
			if(pr<=p):
				# Send the frame
				print('Sending frame '+str(i))
				co.send_frame(list_of_frames[i], sockSend)
				i=i+1
				time.sleep(3)
			else:
				print('Waiting '+str(timeSlot))
				time.sleep(timeSlot)
				continue

		else: # Channel is busy
			print('Channel busy')
			continue


# Function to sense the medium
def sense_medium():
	global isBusyChannel
	if(len(co.shared_buffer)>=1):
		# Means channel is busy
		isBusyChannel=1
	else:
		# Means channel is not busy
		isBusyChannel=0

list_of_frames=co.readfile('input.txt', co.frame_size)
sendThread=threading.Thread(target=send_frame, args=(list_of_frames,)) # create the sending thread
senseThread=threading.Thread(target=sense_medium) # create the sending thread

sendThread.start()
senseThread.start()

sendThread.join()
sendThread.join()