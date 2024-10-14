#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sys/select.h>
#include <unistd.h>
#include "server.hpp"
#include <iostream>
#include "terminal.hpp"
#include <sstream>
#include <vector>

void Server::check(int stat,const std::string& msg)
{
    if(stat < 0){
        printErrorMsg(msg);
        exit(EXIT_FAILURE);
    }
}

Server::Server(int portno) : port(portno)
{
    Terminal::showTitle("SERVER");
    //[1] Creating socket file descriptor: AF_INET: IPV4 - SOCK_STREAM: TCP/IP
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    check(server_fd, "Socket Failed!");
}

void Server::bindToPort() {
    //[2] bind IP server_address and port number
    server_address.sin_port = htons(port); 
    // htons (Host TO Network Short): The htons function converts a 16-bit number (like a port number) from host byte order (whatever the system is using) to network byte order (big-endian).
    server_address.sin_family = AF_INET;          
    server_address.sin_addr.s_addr = INADDR_ANY;  
    int bind_s = bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    check(bind_s, "ERROR: Bind failed!\n");
}

void Server::listenToClient()
{
    //[3] listen to any client request
    int listen_s = listen(server_fd, MAX_CONNECTION_NUMBER);
    check(listen_s, "ERROR: Listen failed!\n");
    printConnectMsg(std::string("Waiting for connection on port...") );
    std::cout << GREEN << port << RESET << std::endl;
}

void Server::acceptValidConnection() {
    
    //[4] accept any valid connection request
    new_socket = accept(server_fd, (struct sockaddr*)&server_address, &addrlen);
    check(new_socket, "ERROR: Accept failed!");
    printConnectMsg("Connected...!\n");
}

std::string Server::receiveFromClient()
{
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
    send(new_socket, response.c_str(), response.size(), 0);
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
            print("Openning calculator...");ERROR: 
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
        closeSocket(server_fd);
}

void Server::startMultiClient() {   
    // [1] Bind to port
    bindToPort();

    // [2] Listen for incoming connections
    listenToClient();

    // Initialize the `select()` master set
    FD_ZERO(&master_set);
    FD_SET(server_fd, &master_set);
    max_sd = server_fd; // Start by tracking the server socket

    std::vector<int> client_sockets(MAX_CONNECTION_NUMBER, 0); // Track client sockets

    while (true) {
        read_fds = master_set; // Copy the master set to read_fds (for select)

        // `select()` to monitor multiple sockets
        int activity = select(max_sd + 1, &read_fds, nullptr, nullptr, nullptr);
        if (activity < 0 && errno != EINTR) {
            perror("select error");
            exit(EXIT_FAILURE);
        }

        // If something happened on the server socket, it’s an incoming connection
        if (FD_ISSET(server_fd, &read_fds)) {
            acceptValidConnection();

            // Add new socket to the client_sockets list
            for (int &client_socket : client_sockets) {
                if (client_socket == 0) {
                    client_socket = new_socket; // Assign the new socket
                    FD_SET(new_socket, &master_set); // Add to the master set
                    if (new_socket > max_sd) max_sd = new_socket; // Update max_sd
                    break;
                }
            }
        }

        // Check all client sockets for incoming data
        for (int &client_socket : client_sockets) {
            if (FD_ISSET(client_socket, &read_fds)) {
                // Clear buffer and receive data
                memset(recv_buffer.data(), 0, recv_buffer.size());
                int valread = recv(client_socket, recv_buffer.data(), RECV_BUFFER_SIZE, 0);

                if (valread == 0) {
                    // Client disconnected
                    std::cout << "Client disconnected!" << std::endl;
                    close(client_socket);
                    FD_CLR(client_socket, &master_set); // Remove socket from master set
                    client_socket = 0; // Mark socket as available
                } else {
                    // Process client command
                    std::string command(recv_buffer.data(), valread);
                    std::cout << "Command received: " << command << std::endl;

                    if (command == "facebook") {
                        std::string response = "Opening Facebook...";
                        send(client_socket, response.c_str(), response.size(), 0);
                    } else if (command == "exit") {
                        std::string response = "Exiting...";
                        send(client_socket, response.c_str(), response.size(), 0);
                        close(client_socket);
                        FD_CLR(client_socket, &master_set); // Remove socket from master set
                        client_socket = 0; // Mark socket as available
                    } else {
                        std::string response = "Unknown command";
                        send(client_socket, response.c_str(), response.size(), 0);
                    }
                }
            }
        }
    }
}


//         //[4] handle the client
//         handleClient(); // Receive the command, process, and send a response
        
//         //[5] close the connection with the current client
//         closeSocket(server_fd);
// }

void Server::handleClientHttp()
{
        while (true) {
        //receive
        std::string command = receiveFromClientHttp();
    //std::cout << command << std::endl;
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
    closeSocket(new_socket);
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
        }
        //[5] close the connection with the current client
        close(server_fd);
}

void Server::closeSocket(int sock){
    close(sock);
}

Server::~Server() {
    printMsg(std::string(30,'-'));
    printWarningMsg("Socket closed!");
    //[7] close the sockets
    closeSocket(server_fd);
}