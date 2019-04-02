import socket

# Accept ip address
filename=str(input("Enter name of file to receive "))
ipaddr=input("Enter ip of server machine ")
port=int(input("Enter port of server machine "))

sock=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.connect((ipaddr,port))

with open(filename,'wb') as f:
	print('receiving data')
	while(True):	
		lines=sock.recv(1024)
		if not lines:
			break
		f.write(lines)

sock.shutdown(socket.SHUT_WR)
