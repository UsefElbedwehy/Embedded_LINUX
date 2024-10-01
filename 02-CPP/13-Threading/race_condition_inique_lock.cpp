#include <iostream>
#include <mutex>
#include <thread>

std::mutex counter_mx;
int counter = 0;

void update_counter(){
    std::unique_lock<std::mutex> l(counter_mx);
    for(int i=0;i<100000;i++){
        counter++;
    }
}


int main(int argc, char const *argv[])
{
    std::thread t1(update_counter);
    std::thread t2(update_counter);
    
    t1.join();
    t2.join();

    std::cout << "counter: " << counter << std::endl;


    return 0;
}
