import socket
import sys

PORT = 6969
HEADER_LENGTH = 10

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    client_socket.connect(('', PORT))
except ConnectionRefusedError:
    print("Connection refused. Is the server running?")
    sys.exit()

# This makes receive non-blocking
client_socket.setblocking(False)

print("Connected to the server.")

while True:
    message = input(">: ")

    if message:
        message = message.encode('utf-8')
        message_header = f"{len(message):<{HEADER_LENGTH}}".encode('utf-8')
        client_socket.send(message_header + message)

    try:
        # Check for incoming messages
        while True:
            header = client_socket.recv(HEADER_LENGTH)
            if not len(header):
                print("Connection closed by the server")
                sys.exit()
            
            message_length = int(header.decode('utf-8').strip())
            message = client_socket.recv(message_length).decode('utf-8')
            print(f"Received: {message}")

    except IOError as e:
        # This is expected when there are no incoming messages to read
        # because of the non-blocking mode.
        pass
    except Exception as e:
        print(f'General error: {e}')
        sys.exit()