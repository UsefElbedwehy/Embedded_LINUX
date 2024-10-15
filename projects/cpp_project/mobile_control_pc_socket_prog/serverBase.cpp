#include "serverBase.hpp"
#include <unistd.h>

void ServerBase::check(int stat, const std::string &msg) {
    if(stat < 0) {
        printErrorMsg(msg);
        exit(EXIT_FAILURE);
    }
}

void ServerBase::bindToPort() {
    server_address.sin_port = htons(port); 
    server_address.sin_addr.s_addr = INADDR_ANY;  
    server_address.sin_family = AF_INET;          
    // htons (Host TO Network Short): The htons function converts a 16-bit number (like a port number) 
                        // from host byte order (whatever the system is using) to network byte order (big-endian).
    int bind_s = bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    check(bind_s, "ERROR: Bind failed!\n");
}

void ServerBase::listenToClient(int max_client_number) {
    printConnectPort("Waiting for connection on port..." , port) ;
    int listen_s = listen(server_fd, max_client_number);
    check(listen_s, "ERROR: Listen failed!\n");
}

void ServerBase::closeSocket(int sock) {
    close(sock);
}