import socket
import select

PORT = 6969
HEADER_LENGTH = 10

# Create the server socket
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# This allows you to reuse the address, preventing "Address already in use" errors
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

try:
    server_socket.bind(('', PORT))
except socket.gaierror as e:
    print(f"Error binding server to localhost at {PORT}: {e}")
    exit()

server_socket.listen()
print(f"Server is now listening on port {PORT}")

# List of all connected client sockets
sockets_list = [server_socket]

# A dictionary to hold client data (e.g., username)
clients = {}

def receive_message(client_socket):
    """Function to handle receiving messages."""
    try:
        message_header = client_socket.recv(HEADER_LENGTH)
        # If a client closes the connection, recv() returns an empty string
        if not len(message_header):
            return False
        message_length = int(message_header.decode('utf-8').strip())
        return {"header": message_header, "data": client_socket.recv(message_length)}
    except:
        # This can happen if a client brutally terminates the connection
        return False

while True:
    # select.select() is the key part.
    # It takes 3 arguments: read_list, write_list, error_list
    # It blocks until one of the sockets is ready for reading.
    read_sockets, _, exception_sockets = select.select(sockets_list, [], sockets_list)

    for notified_socket in read_sockets:
        # If the notified socket is the server socket, it's a new connection
        if notified_socket == server_socket:
            client_socket, client_address = server_socket.accept()

            # For now, we'll just add the new socket to our list
            sockets_list.append(client_socket)
            clients[client_socket] = f"User-{client_address[0]}:{client_address[1]}"

            print(f"Accepted new connection from {client_address[0]}:{client_address[1]}")

        # Otherwise, it's an existing client sending a message
        else:
            message = receive_message(notified_socket)

            # If the client disconnected
            if message is False:
                print(f"Closed connection from {clients[notified_socket]}")
                sockets_list.remove(notified_socket)
                del clients[notified_socket]
                continue

            user = clients[notified_socket]
            print(f"Received message from {user}: {message['data'].decode('utf-8')}")

            # Now, broadcast the message to all other clients
            for client_socket in clients:
                # Don't send the message back to the sender
                if client_socket != notified_socket:
                    client_socket.send(f"{user}: ".encode('utf-8') + message['data'])

    # Handle any sockets that experienced an error
    for notified_socket in exception_sockets:
        sockets_list.remove(notified_socket)
        del clients[notified_socket]