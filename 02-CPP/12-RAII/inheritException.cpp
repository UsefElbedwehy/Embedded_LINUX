#include <iostream>
#include <string>
class InheritException : public std::exception
{
private:
    std::string msg;
public:
    InheritException (const std::string& cmsg): msg(cmsg) {}
    ~InheritException (){}
    const char * what() const noexcept override{
        return msg.c_str();
    }

};



int main(int argc, char const *argv[])
{
    try
    {
        throw InheritException("Custom exception occured!!!!");
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught Exception in main: " << e.what() << '\n';
    }
    
    
    return 0;
}
