#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::condition_variable cv_;
std::mutex cv_mx;
bool ready = false;

void worker(){
    std::unique_lock<std::mutex> cv_lock(cv_mx);
    cv_.wait(cv_lock,[](){return ready;});
    std::cout << "worker thread is processing..." << std::endl;
}

void giver(){
    std::unique_lock<std::mutex> cv_lock(cv_mx);
    ready = true;
    cv_.notify_one();
    std::cout << "giver thread notification..." << std::endl;
}


int main(int argc, char const *argv[])
{
    std::thread t1(worker);
    std::thread t2(giver);
    
    t1.join();
    t2.join();

    return 0;
}
