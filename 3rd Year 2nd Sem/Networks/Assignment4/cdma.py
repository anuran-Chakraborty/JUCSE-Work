import random
from math import log,ceil
class Station: # Class for denoting every station
	
	def __init__(self, stn_num, num_data, cdma_code, frames):
		self.stn_num=stn_num
		self.num_data=num_data
		self.cdma_code=cdma_code
		self.frames=frames

	# Send data corresponding to index of frame list
	def sendData(self,index):

		if(self.frames[index]=='i'): # Meaning idle
			data=0
		elif(self.frames[index]=='0'):
			data=-1
		else:
			data=1

		codeword=[data*self.cdma_code[i] for i in range(len(self.cdma_code))]
		print('Station '+str(self.stn_num)+' sending '+str(codeword))

		return codeword

# Function to create walsh tables
def createWalsh(r):
	global walsh
	walsh=[[int(bin(x&y),13)%2 or -1 for x in range(r)]for y in range(r)]


# Decode dataword for every station
def decode_cdma(codeword, num_stn, max_num_stn):

	for i in range(num_stn):
		data=[codeword[j]*walsh[i][j] for j in range(len(walsh[i]))]
		data=sum(data)
		data=int(data/max_num_stn)

		if(data==-1):
			data=0
			print('Station '+str(i)+' sent '+str(data))
		elif(data==0):
			print('Station '+str(i)+' was idle')
		else:
			print('Station '+str(i)+' sent '+str(data))


def simulate():


	num_stn = input('Enter number of stations (power of 2):')
	num_stn=int(num_stn)

	max_num_stn=2**(ceil(log(num_stn,2)))

	num_data = input('Enter number of data per station:')
	num_data=int(num_data)

	createWalsh(max_num_stn)
	print()
	print(walsh)

	stns=[]

	for i in range(num_stn):
		frames = input('Enter a string of length '+str(num_data)+' data for station '+str(i)+': ')
		frames=list(frames)

		# Now create the station object
		tempstn=Station(i,num_data,walsh[i],frames)
		stns.append(tempstn)

	for i in range(num_stn,max_num_stn):
		frames=num_data*'i'
		frames=list(frames)
		tempstn=Station(i,num_data,walsh[i],frames)
		stns.append(tempstn)

	print()
	
	# Send data for every data
	for i in range(num_data):
		code=[0 for i in range(max_num_stn)]
		# Send for every station
		for j in range(max_num_stn):
			# code=code+stns[j].sendData(i)
			code = [x+y for x,y in zip(code, stns[j].sendData(i))]

		print('Code word in channel is '+str(code))

		print('Decoding for every station')
		decode_cdma(code,num_stn,max_num_stn)
		print(15*'=')
		print()

walsh=[]

simulate()




