#include "terminal.hpp"
#include <iostream>
#define WELCOME_THEME       WHITE

void Terminal::showTitle(const std::string &title)
{
    std::cout << WELCOME_THEME <<"-----------------------------" << std::endl;
    std::cout <<                 "---------- "<< title <<" -----------" << std::endl;
    std::cout <<                 "-----------------------------" << RESET << std::endl;
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

