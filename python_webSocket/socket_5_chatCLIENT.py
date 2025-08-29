import socket


PORT = 6969

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


client.connect(('',PORT))

print(client.recv(1024).decode())

client.sendall(("client has connected, now joining chat").encode())   

connected = True
while True:

    client.sendall((input(">: ")).encode())