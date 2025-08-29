import socket

PORT = 6969

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect(('',6969))
print(client.recv(1024).decode())

client.close()