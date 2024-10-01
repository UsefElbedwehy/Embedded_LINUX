
#include <future>
#include <iostream>
#include <thread>

int add(int a,int b){
    std::cout << "add fuction is called..." << std::endl;
    return a+b;
}


int main(int argc, char const *argv[])
{
    std::packaged_task<int(int,int)> task(add);
    std::future<int> f = task.get_future();
    
    std::thread t1(std::move(task),2,3);
    t1.join();

    std::cout << "waiting for the result..." << std::endl;
    std::cout << "Result: "<< f.get() << std::endl;

    return 0;
}
