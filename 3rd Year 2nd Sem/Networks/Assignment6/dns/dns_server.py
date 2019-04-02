import socket

# Define the mapping
dntoip={'www.abc.com':'123.90.0.1',
		'www.abcd.com':'123.91.23.1',
		'www.gfh.com':'123.98.56.1'}

iptodn={'123.90.0.1':'www.abc.com',
		'123.91.23.1':'www.abcd.com',
		'123.98.56.1':'www.gfh.com'}

# Accept ip address 
port=int(input("Enter port of server machine "))

sock=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.bind(('', port))

# Server mus always run
while(True):

	iporname, addr=sock.recvfrom(1024)
	iporname=iporname.decode()

	if(iporname in dntoip): # If the dn is given return ip
		dataToSend='Required IP is: '+dntoip[iporname]
	elif(iporname in iptodn):
		dataToSend='Required DN is: '+iptodn[iporname]
	else:
		dataToSend='Invalid request'

	sock.sendto(dataToSend.encode(),0,addr)

sock.close()

