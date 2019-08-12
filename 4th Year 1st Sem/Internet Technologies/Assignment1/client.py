import socket
import threading
import common as co
import pickle
import sys

# Function to return a dictionary based on the request
def parseArgs(args):

	req=[]
	i=0
	while i<(len(args)):

		if(args[i].lower()=='get'):
			if(i==len(args)-1 or args[i+1].lower()=='put'): # Error case
				return 0,req
			else:
				req.append({'method':'get','key':args[i+1]})
				i=i+1

		elif(args[i].lower()=='put'):
			if(i==len(args)-2): # Error case
				return 0,req
			else:
				req.append({'method':'put','key':args[i+1],'value':args[i+2]})
				i=i+2

		elif(args[i].lower()=='getother'):
			if(i==len(args)-2): # Error case
				return 0,req
			else:
				req.append({'method':'getother','key':args[i+2],'username':args[i+1]})
				i=i+2
					
		elif(args[i].lower()=='upgrade'):
			req.append({'method':'upgrade'})
		else:
			return 0,req
		i=i+1

	return 1,req

sockClient=co.createConn(port=int(sys.argv[2]),ip=sys.argv[1])

uname=input('Enter a username: ')
sockClient.sendall(uname.encode())

print('Usage:')
print('get key		 : To get value corresponding to a key')
print('put key value : To insert a value corresponding to a key')
print('upgrade		 : To upgrade user status')
print('getother username key : To get value of another user (only allowed if manager)')

while(True):
	# Take input
	request=input('>> ')
	if(request.lower()=='exit'):
		break
	retVal,req=parseArgs(request.split(' '))

	if(retVal==0):
		print('Invalid arguments')
		continue

	# print(req)

	req=pickle.dumps(req)
	# Send the dictionary through socket
	sockClient.sendall(req)

	# Wait for response
	response=sockClient.recv(1024)
	response=pickle.loads(response)

	print(response)