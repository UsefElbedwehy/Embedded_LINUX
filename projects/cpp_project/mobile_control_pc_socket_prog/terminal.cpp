#include "terminal.hpp"
#include <iostream>
#include <string>

void Terminal::showTitle(const std::string &title)
{
    std::cout << BLUE << std::string(29,'-') << std::endl;
    std::cout << "---------- "<< title <<" -----------" << std::endl;
    std::cout << std::string(29,'-') << RESET << std::endl;
}

void Terminal::print(const std::string &msg)
{
    std::cout << msg << std::endl;
}

void Terminal::printInColor(const std::string &msg, const std::string &color)
{
    std::cout << color << msg << RESET << std::endl;
}
void Terminal::printInColorSameline(const std::string &msg1,const std::string &msg2, const std::string &color)
{
    std::cout << color << msg1 << RESET << msg2<< std::endl;
}
// ----------------------------------------------------------------------------------
void Terminal::printErrorMsg(const std::string &msg)
{
    std::cout << RED << msg << RESET ;
}

void Terminal::printConnectMsg(const std::string &msg)
{
    std::cout << GREEN << msg << RESET ;
}

void Terminal::printWarningMsg(const std::string &msg)
{
    std::cout << YELLOW << msg << RESET ;
}

void Terminal::printRecvMsg(const std::string &msg)
{
    std::cout << MAGENTA << msg << RESET ;
}

void Terminal::printSentMsg(const std::string &msg)
{
    std::cout << BLUE << msg << RESET ;
}

void Terminal::printMsg(const std::string &msg)
{
    std::cout << WHITE << msg << RESET ;
}

