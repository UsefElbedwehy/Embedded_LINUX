import socket

#socket:socket creation(domain:socket family(IPv4),socket type:TCP or UDP,protocol:formal standard)
#TCP-> SOCK_STREAM
#UDP->SOCK_DGRAM
#protocol: network protocols are formal standards and policies comprised of rules and formates that define the communication between two or more devices over the network.
# cat /etc/protocols
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

#get host IP
hostIP = socket.gethostbyname(socket.gethostname())
print("="*30)
print(f"Your IP is : {hostIP}")
print("="*30)

#bind: connect to address and port number
server_socket.bind((hostIP , 4000))

#listen
server_socket.listen(5)
print("Server is listening on port 4000...")

try: 
    while True:
        #accept
        client_socket, client_address = server_socket.accept()
        print(f"Connection established with {client_address}")

        while True:
            try:
                 #read
                received_data = client_socket.recv(1024*4)

                if not received_data:
                    break  # Connection closed by the client

                #-------show data---------
                print("="*30)
                print(f"the address {client_address} is sending to you this msg: ")
                print(f" -----> {received_data.decode('UTF-8')}")
                print("="*30)

                #write
                transmiting_data = str(input("Please enter the msg that u want to send: "))
                encoded_msg = transmiting_data.encode('UTF-8')
                client_socket.send(encoded_msg)
            except ConnectionResetError:
                print(f"Connection with {client_address} was reset.")
                break

        #close
        client_socket.close()
        print(f"Connection with {client_address} closed.")
        
except KeyboardInterrupt:
    print("\nServer is shutting down.")
finally:
    #close the server
    server_socket.close()
    
    
    





