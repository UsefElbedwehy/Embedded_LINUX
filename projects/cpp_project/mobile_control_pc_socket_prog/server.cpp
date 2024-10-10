#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>
#include "server.hpp"
#include <iostream>
#include "terminal.hpp"
#include <sstream>

Server::Server(int portno) : port(portno)
{
    Terminal::showTitle("SERVER");
    //[1] Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        Terminal::printInColor("Socket failed!",Terminal::RED);
        exit(EXIT_FAILURE);
    }
}

void Server::bindToPort() {
    //[2] bind IP server_address and port number
    server_address.sin_port = htons(port);  // IP port
    server_address.sin_family = AF_INET;           // must be AF_INET
    server_address.sin_addr.s_addr = INADDR_ANY;   // IP address

    //  Bind the socket to the port
    int bind_s = bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    if (bind_s < 0) {
        Terminal::printInColor("Bind failed!",Terminal::RED);
        exit(EXIT_FAILURE);
    }
}

void Server::listenToClient()
{
    //[3] listen to any client request
    int listen_s = listen(server_fd, MAX_CONNECTION_NUMBER);
    if (listen_s < 0) {
        Terminal::printInColor("Listen failed!",Terminal::RED);
        exit(EXIT_FAILURE);
    }
    std::cout << Terminal::CYAN << "Waiting for connection on port " << port << "..." << Terminal::RESET << std::endl;
}

void Server::acceptValidConnection() {
    socklen_t addrlen = sizeof(server_address);
    //[4] accept any valid connection request
    new_socket = accept(server_fd, (struct sockaddr*)&server_address, &addrlen);
    if (new_socket < 0) {
        Terminal::printInColor("Accept failed!",Terminal::RED);
        exit(EXIT_FAILURE);
    }
    Terminal::printInColor("Connected!",Terminal::GREEN);
}
std::string Server::receiveFromClient() {
    // (1)-Clear buffer before receiving
    memset(recv_buffer.data(), 0, recv_buffer.size());

    // (2)-Receiving data from the client
    int recv_s = recv(new_socket, recv_buffer.data(), recv_buffer.size() - 1, 0);
    // (2)-(1) check receive status
    if (recv_s < 0) {
        Terminal::printInColor("Client disconnected!", Terminal::RED);
        return "exit";  // Return "exit" on failure or disconnect
    }else if(recv_s == 0){
        Terminal::printInColor("Receiving failed!", Terminal::RED);
        return "exit";
    }
    // (3)-Convert received data to string
    std::string request(recv_buffer.data(), recv_s);  
    return request;
}

std::string Server::receiveFromClientHttp()
{
        // Clear buffer before receiving
    memset(recv_buffer.data(), 0, recv_buffer.size());

    // Receiving data from the client
    int recv_s = recv(new_socket, recv_buffer.data(), recv_buffer.size() - 1, 0);
    if (recv_s <= 0) {
        Terminal::printInColor(recv_s == 0 ? "Client disconnected!" : "Receiving failed!", Terminal::RED);
        return "exit";  // Return "exit" on failure or disconnect
    }

    std::string request(recv_buffer.data(), recv_s);  // Convert received data to string
    Terminal::printInColor("Raw HTTP Request: " + request, Terminal::CYAN);

    // Locate the body start (after headers)
    size_t body_start = request.find("\r\n\r\n");
    if (body_start != std::string::npos) {
        // Extract the body part (after "\r\n\r\n")
        std::string body = request.substr(body_start + 4);

        // Use a stringstream to read the body line by line
        std::istringstream body_stream(body);
        std::string line, last_line;

        // Extract the last non-empty line (in case body contains multiple lines)
        while (std::getline(body_stream, line)) {
            if (!line.empty()) {
                last_line = line;
            }
        }

        if (!last_line.empty()) {
            // Trim any trailing spaces or newline characters from the last line
            last_line.erase(last_line.find_last_not_of(" \n\r\t") + 1);
            Terminal::printInColor("Command received: " + last_line, Terminal::YELLOW);
            return last_line;  // Return the command from the last line
        }
    }

    // If the body or command is missing, return the full request as a fallback
    Terminal::printInColor("No command found in request.", Terminal::RED);
    return request;
}

void Server::sendToClient(const std::string& transData) {
    std::string response = "HTTP/1.1 200 OK\r\n";
    response += "Content-Type: text/plain\r\n";
    response += "Connection: keep-alive\r\n"; // Keep the connection alive
    response += "Content-Length: " + std::to_string(transData.size()) + "\r\n";
    response += "\r\n"; // End of headers
    response += transData; // Add the actual response body

    int send_s = send(new_socket, response.c_str(), response.size(), 0);
    if (send_s < 0) {
        Terminal::printInColor("Sending failed!", Terminal::RED);
    } else {
        Terminal::printInColor("Response is sent!", Terminal::YELLOW);
    }
}


void Server::handleClient() {
    while (true) {
        //receive
        std::string command = receiveFromClient();

        // Process the command and take action
        if (command == "facebook")
        {
            print("Openning facebook...");
            openFacebook();
        }else if (command == "whatsapp") {
            print("Openning whatsapp...");
            openWhatsapp();
        }else if (command == "github") {
            print("Openning github...");
            openGithub();
        }else if (command == "linkedin") {
            print("Openning linkedin...");
            openLinkedin();
        }else if (command == "youtube") {
            print("Openning youtube...");
            openYoutube();
        }else if (command == "calculator") {
            print("Openning calculator...");
            openCalculator();
        }else if (command == "vscode") {
            print("Openning vscode...");
            openVSCode();
        }else if (command == "exit") {
            print("exiting...");
            break;
        }else{
            print("sorry...unknown command ;(");
            continue;;    
        }

        // Send a response to the client
        std::string response = command + " is opened!";
        sendToClient(response);

    }
}

void Server::handleClientHttp()
{
        while (true) {
        //receive
        std::string command = receiveFromClientHttp();

        // Process the command and take action
        if (command == "facebook")
        {
            print("Openning facebook...");
            openFacebook();
        }else if (command == "whatsapp") {
            print("Openning whatsapp...");
            openWhatsapp();
        }else if (command == "github") {
            print("Openning github...");
            openGithub();
        }else if (command == "linkedin") {
            print("Openning linkedin...");
            openLinkedin();
        }else if (command == "youtube") {
            print("Openning youtube...");
            openYoutube();
        }else if (command == "calculator") {
            print("Openning calculator...");
            openCalculator();
        }else if (command == "vscode") {
            print("Openning vscode...");
            openVSCode();
        }else if (command == "exit") {
            print("exiting...");
            break;
        }else{
            print("sorry...unknown command ;(");
            break;    
        }

        // Send a response to the client
        std::string response = command + " is opened!";
        sendToClient(response);

    }
}

// work: connect and accept client, receive and respone then close, and reconnect again 
void Server::startHttp()
{
        //[1] bind to port
        bindToPort();

        while (true) {
        //[2] listen for incoming connections
        listenToClient();

        //[3] accept a new connection
        acceptValidConnection();

        //[4] handle the client
        handleClientHttp(); // Receive the command, process, and send a response

        closeSocket();
        }
        //[5] close the connection with the current client
}

void Server::start()
{   
        //[1] bind to port
        bindToPort();

        //[2] listen for incoming connections
        listenToClient();

        //[3] accept a new connection
        acceptValidConnection();


        //[4] handle the client
        handleClient(); // Receive the command, process, and send a response

        //[5] close the connection with the current client
        closeSocket();
}

void Server::closeSocket(){
    close(new_socket);
}

Server::~Server() {
    std::cout << std::string(30,'-') << std::endl;
    //[7] close the sockets
    std::cout << "socket closed!" << std::endl;
    close(new_socket);
    close(server_fd);
}