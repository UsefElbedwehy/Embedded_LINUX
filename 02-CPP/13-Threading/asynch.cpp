#include <future>
#include <iostream>
#include <thread>

typedef long int ull;

ull findOdd(ull start,ull end){
    std::cout << "[in func]Thread ID: " << std::this_thread::get_id() << std::endl;
    ull oddSum = 0;
    for(ull i = start;i<=end;i++){
        if(i & 1){
            oddSum += i ;
        }
    }
    return oddSum;
}


int main(int argc, char const *argv[])
{
    ull start = 0;
    ull end = 190000000;
    std::cout << "[in main]Thread ID: " << std::this_thread::get_id() << std::endl;
    std::cout << "Thread created if the policy is std::launch::async!!" << std::endl;
    std::future<ull> oddsum = std::async(std::launch::deferred,findOdd,start,end);
    
    std::cout << "waiting for the result..." << std::endl;
    std::cout << "OddSum: " << oddsum.get() << std::endl;
    std::cout << "completed!" << std::endl;

    return 0;
}