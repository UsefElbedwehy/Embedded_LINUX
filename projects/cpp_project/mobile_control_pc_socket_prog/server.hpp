#ifndef SERVER_HPP
#define SERVER_HPP

#include "commands.hpp"
#include "terminal.hpp"
#include <array>
#include <string>
#include <netinet/in.h>
#include <sys/socket.h>

class Server : private Terminal , private Commands 
{
private:
    int server_fd;
    int port;
    int new_socket;
    sockaddr_in server_address;
    static const int PORT_NUMBER ;
    static const int MAX_CONNECTION_NUMBER = 5;
    static const int SEND_BUFFER_SIZE      = 100;
    static const int RECV_BUFFER_SIZE      = 1024;
    socklen_t addrlen = sizeof(server_address);
    std::array<char, RECV_BUFFER_SIZE> recv_buffer{};
    std::string response = "Msg Received!";
    fd_set master_set , read_fds;  // master set and temp set for `select()`
    int max_sd;     // Maximum socket descriptor
    void bindToPort();
    void listenToClient();
    void acceptValidConnection();
    void startMultiClient();
    void check(int stat,const std::string& msg);
public:

    void start();
    void startHttp();
    std::string receiveFromClient();
    std::string receiveFromClientHttp();
    void sendToClient(const std::string& transData);
    void handleClient();
    void handleClientHttp();
    void closeSocket(int sock);
    Server(int portno); //creste Socket
    ~Server(); //close socket
};


#endif // SERVER_HPP