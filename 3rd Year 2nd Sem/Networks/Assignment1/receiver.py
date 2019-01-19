import errorchecker as err

# Function to read from the input file and convert to a list of frames
def readfile(filename, no_of_bits):
	# Open the file for reading
	print('Reading file '+filename)
	f=open(filename,'r')
	data=f.read()

	# Now split the data into frames
	# list_of_frames=[data[i:i+no_of_bits] for i in range(0, len(data), no_of_bits)]
	list_of_frames=data.split('\n')
	list_of_frames=list_of_frames[0:-1]
	return list_of_frames

# Check for error by checksum
def check_checksum(list_of_frames, no_of_bits):

	list_of_frames=[list_of_frames[i][len(err.generator_poly)-1:] for i in range(len(list_of_frames))]
	
	chksum=err.checksum(list_of_frames=list_of_frames, no_of_bits=no_of_bits)
	if(int(chksum,2)==0):
		print('No error in data detected by checksum')
	else:
		print('Error detected by checksum')

# Check for error by lrc
def check_lrc(list_of_frames, no_of_bits):

	lrcval=err.lrc(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	if(int(lrcval,2)==0):
		print('No error in data detected by LRC')
	else:
		print('Error detected by LRC')

# Check for error by vrc
def check_vrc(list_of_frames):

	flag=True
	
	for i in range(len(list_of_frames)):
		if(list_of_frames[i].count('1')%2!=0):
			print('Error detected in frame '+str(i+1)+' by VRC')
			flag=False

	if(flag):
		print("No error detected in data by VRC")

# Check for error by crc
def check_crc(list_of_frames, generator):

	flag=True
	for i in range(len(list_of_frames)):
		if(int(err.modulo2div(list_of_frames[i],err.generator_poly),2)!=0):
			print('Error detected in frame '+str(i+1)+' by CRC')
			flag=False

	if(flag):
		print("No error detected in data by CRC")

no_of_bits=err.no_of_bits

list_of_frames=readfile('csum_op.txt',no_of_bits)
check_checksum(list_of_frames, no_of_bits)

list_of_frames=readfile('lrc_op.txt',no_of_bits)
check_lrc(list_of_frames, no_of_bits)

list_of_frames=readfile('vrc_op.txt',no_of_bits+1)
check_vrc(list_of_frames)

list_of_frames=readfile('crc_op.txt',no_of_bits=no_of_bits+len(err.generator_poly)-1)
check_crc(list_of_frames,generator=err.generator_poly)