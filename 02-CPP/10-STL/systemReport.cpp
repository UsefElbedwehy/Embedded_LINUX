#include <iostream>
#include <array>
#include <string>

int main(int argc, char const *argv[])
{
    std::array<std::string, 4> commands = {
        "cat /etc/hosts",
        "cat /etc/issue",
        "cat /etc/os-release",
        "cat /etc/fstab"
    };

    for (const auto &command : commands){
        if(!command.empty()){
            std::cout << std::string(100,'-') << std::endl << command << std::endl;
            std::system(command.c_str());
        }
    }



    return 0;
}
