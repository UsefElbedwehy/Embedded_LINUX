#include <cstdlib>
#include <cstring>
#include <iostream>
#include <array>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    const int PORT = 8000;
    const int BUFFER_SIZE=1024;
    socklen_t size;
    std::array<char, BUFFER_SIZE> buffer;
    bool isExit = false;

    //[1] create socket (ip address and port)
    int server_df = socket(AF_INET, SOCK_STREAM, 0);
    if(server_df < 0){
        std::cout << "ERROR: can't create socket. Socket failed!" << std::endl;
        exit(EXIT_FAILURE);
    }
    //[2] bind to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    int bind_s = bind(server_df, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_s < 0){
        std::cout << "ERROR: Bind failed!" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    //[3] listen to client
    int listen_s = listen(server_df, 5);
    if(listen_s < 0){
        std::cout << "ERROR: listen failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    //[4] accept valid client request
    int new_socket = accept(server_df, (struct sockaddr *)&server_address, &size);
    if (new_socket < 0)
    {
        std::cout << "ERROR: Acepting failed!" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    while (true)
    {
    std::strcpy(buffer.data(),"server connected...\n");
    send(new_socket, buffer.data() , buffer.size(), 0);
    std::cout << "Connected with client..." << std::endl;
    std::cout << "Enter # to end the connection" << std::endl;
    std::cout << "Client: ";
    do
    {
        //[5] receive
        recv(new_socket, buffer.begin(), buffer.size(), 0);
        std::cout << buffer.data() << std::endl;
        if (*buffer.data() == '#')
        {
            *buffer.data() = '*';
            isExit = true;
        }
    } while (*buffer.data() != '*');
    do
    {
        std::cout << "\nServer: " << std::endl;
        do{
            std::cin.getline(buffer.data(),buffer.size());
            send(new_socket,buffer.data(), buffer.size(), 0);
            if (*buffer.data() == '#')
            {
                send(new_socket,buffer.data(), buffer.size(), 0);
                *buffer.data() = '*';
                isExit = true;
            }
        }while (*buffer.data() != '*');

        std::cout << "Client: " << std::endl;
        do{
        recv(new_socket, buffer.begin(), buffer.size(), 0);
        std::cout << buffer.data() << std::endl;
        if (*buffer.data() == '#')
        {
            *buffer.data() = '*';
            isExit = true;
        }
        } while (*buffer.data() != '*');
        

    } while (!isExit);
    std::cout << "connection terminated..." << std::endl;
    std::cout << "Goodbye.." << std::endl;
    isExit = false;
    exit(EXIT_FAILURE);
    }
    //[7] close socket
    //close(new_socket);
    close(server_df);
    return 0;

} //main
    




