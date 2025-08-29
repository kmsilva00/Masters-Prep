import socket

PORT = 6969
try:
    server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)

except socket.sockerror as e:
    print(f"error creating server socket {e}")


try:
    server.bind(('',PORT))
except socket.gaierror as e:
    print(f"error binding server to localhost at {PORT}. {e}")


server.listen(3)
print("server is now listening")

while True:
    conn_list = list()
    conn, ip = server.accept()

    conn_list.append((ip))
    
    

    conn.sendall(f"current clients connected {conn_list}".encode())
    
    if conn.recv(1024).decode() == "exit":
        server.close()
        break

    while conn :
        print(conn.recv(1024).decode())

        if conn.recv(1024).decode() == "exit":
            server.close()
            break
