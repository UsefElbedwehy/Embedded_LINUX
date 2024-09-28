#include <iostream>
#include <stdexcept>

// Rethrowing (throw;) allows an exception to be propagated up the call stack.
// This is useful when local cleanup or logging is needed before letting the higher-level handler deal with the exception.
// You cannot pass any argument when rethrowing an exception; you simply use throw; to rethrow the current caught exception.


void riskyFunc(){
            try{
                throw std::runtime_error("something went wrong!");
            }catch(const std::runtime_error& e){
                std::cout << "Caught in riskyFunc: "<< e.what() << std::endl;
                throw;
            }
        }


int main(int argc, char const *argv[])
{
    try{
        riskyFunc();
    }catch(const std::exception& e){
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
    


    return 0;
}
