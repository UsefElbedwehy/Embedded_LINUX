
#include "server.hpp"
#include <cstring>
#include <string>
#include "commands.hpp"
#include "terminal.hpp"

int main(int argc, char const *argv[])
{
    const int portNumber = 8080;
    Commands cmd;
    Terminal ter;
    std::string command;

    Server server(portNumber);

    server.start();

    return 0;
}
