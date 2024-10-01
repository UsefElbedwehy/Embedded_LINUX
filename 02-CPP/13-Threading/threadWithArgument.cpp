#include <iostream>
#include <thread>
// task1 with argument
void task1(int x){
    std::cout << "msg no.: " << x << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread t1(task1,32);;
    t1.join();

    return 0;
}
