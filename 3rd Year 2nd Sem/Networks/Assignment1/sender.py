import errorchecker as err
import random

no_of_errors=0
# Function to ad two numbers
def andop(a,b):
	andstr=''
	for i in range(len(a)):
		if(a[i]=='0' or b[i]=='0'):
			andstr+='0'
		else:
			andstr+='1'
	return andstr

# Function to read from the input file and convert to a list of frames
def readfile(filename, no_of_bits):
	# Open the file for reading
	f=open(filename,'r')
	data=f.read()

	# Now split the data into frames
	list_of_frames=[data[i:i+no_of_bits] for i in range(0, len(data), no_of_bits)]
	return list_of_frames

# Coverts dataword to codeword and wrote to the appropriate file
def dataword_to_codeword(list_of_frames, no_of_bits, error_list_frames, error_bit_list):
	global no_of_errors

	print('Writing to checksum file')
	write_chksum(list_of_frames, no_of_bits, error_list_frames, error_bit_list)
	print('Writing to lrc file')
	write_lrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list)
	print('Writing to vrc file')
	write_vrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list)
	print('Writing to crc file')
	write_crc(list_of_frames, no_of_bits, error_list_frames, error_bit_list)

# Function to write the checksum frames to file
def write_chksum(list_of_frames, no_of_bits, error_list_frames, error_bit_list):
	# error_list_frames contains the list of frames to introduce the error into
	# error_bit_list is a list of lists containing bit posiiton of errrors in each frame
	chksum=err.checksum(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	list_of_frames2=list_of_frames[:]
	list_of_frames2.append(chksum)

	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=ins_error(list_of_frames2, error_list_frames[i], error_bit_list[i])

	with open('csum_op.txt', 'w') as f:
		for item in list_of_frames2:
			item=item='0'*(len(err.generator_poly)-1)+item
			f.write("%s" % item)

# Function to write the lrc frames to file
def write_lrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list):
	
	lrcval=err.lrc(list_of_frames=list_of_frames, no_of_bits=no_of_bits)

	list_of_frames2=list_of_frames[:]
	list_of_frames2.append(lrcval)
	
	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=ins_error(list_of_frames2, error_list_frames[i], error_bit_list[i])


	with open('lrc_op.txt', 'w') as f:
		for item in list_of_frames2:
			item='0'*(len(err.generator_poly)-1)+item
			f.write("%s" % item)

# Function to write the vrc frames to file
def write_vrc(list_of_frames, no_of_bits, error_list_frames, error_bit_list):

	list_of_frames2=err.vrc(list_of_frames=list_of_frames)[:]
	
	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=ins_error(list_of_frames2, error_list_frames[i], error_bit_list[i])

	with open('vrc_op.txt', 'w') as f:
		for item in list_of_frames2:
			item='0'*(len(err.generator_poly)-2)+item
			f.write("%s" % item)

# Function to write the crc frames to file
def write_crc(list_of_frames, generator, error_list_frames, error_bit_list):

	list_of_frames2=err.crc(list_of_frames=list_of_frames, generator=err.generator_poly, no_of_bits=err.no_of_bits)[:]
	
	# Inserting error
	for i in range(len(error_list_frames)):
		list_of_frames2=ins_error(list_of_frames2, error_list_frames[i], error_bit_list[i])
	
	with open('crc_op.txt', 'w') as f:
		for item in list_of_frames2:
			f.write("%s" % item)

# Function to insert an error
def insert_error(list_of_frames, number_of_errors):

	random.seed(5)

	for i in range(number_of_errors):
		# Select a random index
		index=random.randint(0,len(list_of_frames)-1)
		size=len(list_of_frames[index])
		num=random.randint(0,2**size-1)
		num=bin(num)[2:].zfill(size)
		list_of_frames[index]=andop(list_of_frames[index],num)

	return list_of_frames

def ins_error(list_of_frames, frame_no, list_of_bit):

	list_of_frames2=list_of_frames[:]
	frame=list_of_frames2[frame_no]
	new=list(frame)

	# Inserting error in the given bit position here
	for i in range(len(list_of_bit)):
		
		if(new[list_of_bit[i]]=='0'):
			new[list_of_bit[i]]='1'
		elif (new[list_of_bit[i]]=='1'):
			new[list_of_bit[i]]='0'
	list_of_frames2[frame_no]=''.join(new)

	return list_of_frames2

