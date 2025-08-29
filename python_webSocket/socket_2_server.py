import socket

PORT = 6969

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

server.bind(('',PORT))

server.listen(2)

while True:
    conn, ip = server.accept()
    print(f" {ip} has connected at port {PORT}")

    conn.send('aknowledged'.encode())
    server.close()
    break