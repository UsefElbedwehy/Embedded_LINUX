import socket

#socket
client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

print("-"*30)
clientIP = socket.gethostbyname(socket.gethostname())
print(f"You IP is : {clientIP}")
print("-"*30)

#connect
client_socket.connect((clientIP , 4000))

try:
    while True:
        #write

        transmiting_data = input("Please enter the msg that u want to send: ")
        encoded_msg = transmiting_data.encode('UTF-8')
        client_socket.send(encoded_msg)

        #read
        print("-"*30)
        receive_data = client_socket.recv(1024*4)
        decoded_msg = receive_data.decode('UTF-8')
        print(f"{clientIP} is sending this msg for u: {decoded_msg}")
        print("-"*30)

except KeyboardInterrupt:
    print("\nConnection closed.")

finally:
    client_socket.close()
    