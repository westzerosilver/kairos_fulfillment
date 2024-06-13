import socket
import threading

clients = []

def handle_client(client_socket, client_address):
    while True:
        
        try:
            message = client_socket.recv(1024).strip()
            if not message:
                # break
                pass
            
            
            
            print(f'Client {client_address}: {message}')
            broadcast(f"Client {client_address}: {message}", client_socket)
        except ConnectionResetError:
            break

    client_socket.close()
    print(f'Connection with {client_address} closed')
    clients.remove(client_socket)

def broadcast(message, sender_socket):
    for client in clients:
        if client != sender_socket:
            try:
                client.send(message.encode())
            except:
                client.close()
                clients.remove(client)


def send_messages():
    while True:
        message = input("Enter message to broadcast: ")
        broadcast(message, None)

def start_server(host='', port=8098):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((host, port))
    server_socket.listen(5)
    print(f'Server listening on {host}:{port}')

    threading.Thread(target=send_messages).start()

    while True:
        client_socket, client_address = server_socket.accept()
        print(f'Connection from {client_address}')
        clients.append(client_socket)
        client_handler = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_handler.start()


if __name__ == '__main__':
    start_server()