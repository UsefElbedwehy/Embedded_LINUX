#include <cstdlib>
#include <cstring>
#include <iostream>
#include <array>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    int client;
    int new_socket;
    const int PORT = 8000;
    const int buffer_size = 1024;
    int isExit = false;
    std::array<char, buffer_size> buffer;
    std::string ip("127.0.0.1");
    struct sockaddr_in server_address;

    //[1] create socket
    client = socket(AF_INET, SOCK_STREAM, 0);
    if(client < 0){
        std::cout << "ERROR: socket failed!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Client socket is created!" << std::endl;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    if(connect(client, (struct sockaddr *)&server_address, sizeof(server_address)) == 0){
        std::cout << "Connecting to the server..." << std::endl;
    }

    recv(client, buffer.data(), buffer_size, 0);    
    std::cout << "Connection confirmed." << std::endl;
    std::cout << "Enter # to end the connection." << std::endl;

    do
    {
        std::cout << "Client: " ;
        do
        {
            std::cin.getline(buffer.data(),buffer_size);
            send(client, buffer.data(), buffer_size, 0);
            if(*buffer.data() == '#'){
                send(client, buffer.data(), buffer_size, 0);
                *buffer.data() = '*';
                isExit = true;
            }
            
        } while (*buffer.data() != 42);
        std::cout << "Server: ";
        do
        {
            recv(client, buffer.data(),buffer_size, 0);
            std::cout << buffer.data() << " " ;
            if(*buffer.data() == '#'){
                *buffer.data() = '*';
                isExit = true;
            }
        } while (*buffer.data() != 42);
        std::cout << std::endl;
        
        
    } while (!isExit);
    std::cout << "connection terminated..." << std::endl;
    std::cout << "Goodbye.." << std::endl;
    close(client);

    return 0;
}
