import asyncio
import websockets

import socket
import threading
import pickle

# Class to store key value for each client
class KeyValueClient:

	def __init__(self,username):
		self.valstore={}
		self.mode='guest'
		self.username=username

	def _change_mode(self):
		self.mode='admin'

	def _getValue(self,key):
		if(key not in self.valstore):
			return 'Invalid key'
		return self.valstore[key]

	def _putValue(self,key,value):

		self.valstore[key]=value
		return 'Successful'

	# Function to take action on the requests
	def takeAction(self,req):

		res=[]

		for reqs in req:
			if(reqs['method'].lower()=='get'):
				res.append(self._getValue(reqs['key']))

			elif(reqs['method'].lower()=='put'):
				res.append(self._putValue(reqs['key'],reqs['value']))

			elif(reqs['method'].lower()=='upgrade'):
				self._change_mode()
				res.append('mode change successfull')

			elif(reqs['method'].lower()=='getother'):
				if(self.mode=='guest' and self.username!=reqs['username']):
					res.append('Access Denied')
				elif(self.username==reqs['username'] or self.mode=='admin'):

					if(reqs['username'] in global_dict):
						res.append(global_dict[reqs['username']]._getValue(reqs['key']))
					else:
						res.append('Invalid username')

		return res

global_dict={}

# Function to service a client
async def serviceClient(clientAddr,path):

	print('Connected to client')
	# Fetch username
	uname=await clientAddr.recv()
	client=KeyValueClient(uname) # Create client by that username
	global_dict[uname]=client

	while True:

		requestC=await clientAddr.recv() # Receive the request dictionary
		requestC=pickle.loads(requestC)
		res=client.takeAction(requestC)
		res=pickle.dumps(res)
		print('Hi')
		await clientAddr.send(res)

start_server = websockets.server.serve(serviceClient, '', 8765, ping_timeout=100000, ping_interval=100000)
asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
