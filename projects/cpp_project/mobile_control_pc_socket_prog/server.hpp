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
    static const int RECV_BUFFER_SIZE      = 1023;
    std::array<char, RECV_BUFFER_SIZE> recv_buffer{};
    std::string response = "Msg Received!";
    void bindToPort();
    void listenToClient();
    void acceptValidConnection();
public:
    void start();
    void startHttp();
    std::string receiveFromClient();
    std::string receiveFromClientHttp();
    void sendToClient(const std::string& transData);
    void handleClient();
    void handleClientHttp();
    void closeSocket();
    Server(int portno); //creste Socket
    ~Server(); //close socket
};


#endif // SERVER_HPP