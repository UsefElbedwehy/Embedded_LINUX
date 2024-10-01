#include <iostream>
#include <string>
#include <thread>

class MyFunctor
{
public:
    void operator()(int num){
        std::cout << "arg: "<< num << std::endl;
    }
};



int main(int argc, char const *argv[])
{
    std::thread t1(MyFunctor(),143);
    t1.join();
    std::thread t2([](std::string msg){std::cout << "msg: " << msg << std::endl;},"Hello, Usef!");
    t2.join();
    
    return 0;
}
