#ifndef TERMINALL_HPP
#define TERMINALL_HPP

#include <string>

class Terminal
{
protected:
    // ANSI escape codes for colors
    const std::string WHITE     = "\033[37m";
    const std::string CYAN      = "\033[36m";
    const std::string RED       = "\033[31m";
    const std::string GREEN     = "\033[32m";
    const std::string YELLOW    = "\033[33m";
    const std::string RESET     = "\033[0m";
public:
    void showTitle(const std::string &title);
    void print(const std::string &msg);
    void printInColor(const std::string &msg,const std::string& color);
    void printInColorSameline(const std::string &msg1,const std::string &msg2, const std::string &color);

};


#endif