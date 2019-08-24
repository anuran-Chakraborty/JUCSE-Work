import asyncio
import websockets
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


async def clientRun():
	ws_url='ws://'+sys.argv[1]+':'+str(sys.argv[2])
	# async with websockets.connect(ws_url) as sockClient:
	sockClient=await websockets.connect(ws_url)
	# Accept username
	uname=input('Enter a username: ')
	await sockClient.send(uname)

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
		await sockClient.send(req)

		# Wait for response
		try:
			response=await sockClient.recv()
		except:
			# Reconnect
			print('Reconnecting...')
			sockClient=await websockets.connect(ws_url)
			# response=await sockClient.recv()
					
		response=pickle.loads(response)

		print(response)

asyncio.get_event_loop().run_until_complete(clientRun())
