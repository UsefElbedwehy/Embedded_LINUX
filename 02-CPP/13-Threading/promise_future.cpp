#include <future>
#include <iostream>
#include <thread>

int summ(int arg1, int arg2){return arg1 + arg2;}


int main(int argc, char const *argv[])
{
    std::promise<int> promiseObj;
    std::future<int>  FutureObj = promiseObj.get_future();

    std::thread sumThread([&promiseObj](){
        int res = summ(20,30);
        std::this_thread::sleep_for(std::chrono::seconds(2));
        promiseObj.set_value(res);
    });

    int sum_res = FutureObj.get();
    std::cout << "summation result: " << sum_res << std::endl;

    sumThread.join();    

    return 0;
}
