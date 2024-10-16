#include <chrono>
#include <iostream>
#include <thread>

//[1] function
void fun(int x){
    std::cout << "Thread started" << std::endl;
    while (x-- > 0){
        std::cout << x << " " ;
    }
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(7));
    std::cout << "Thread finished" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(fun,10);
    std::cout << "main() before" << std::endl;
    // t1.join();
    // if(t1.joinable()){
    //     t1.join();
    // }
    t1.detach();
    std::cout << "main() after" << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(7));
    return 0;
}
