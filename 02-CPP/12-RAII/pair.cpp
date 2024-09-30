#include <iostream>
#include <utility>


int main(int argc, char const *argv[])
{
    std::pair<int , std::string> mypair(23,"Usef");
    
    std::cout << "My name: " << mypair.second  << std::endl;
    std::cout << "My age: " << mypair.first << std::endl;


    return 0;
}
