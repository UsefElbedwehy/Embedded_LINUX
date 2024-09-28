#include <iostream>
#include <stdexcept>

void checkAge(int age){
    if(age < 18){
        throw(std::runtime_error("Underage exception!"));
    }else{
        std::cout << "You are allowed to proceed." << std::endl;
    }
}


int main(int argc, char const *argv[])
{
    try{
        checkAge(16);
    }catch(const std::runtime_error error){
        std::cout << "Caught an exception: " << error.what() << std::endl;
    }
    

    return 0;
}
