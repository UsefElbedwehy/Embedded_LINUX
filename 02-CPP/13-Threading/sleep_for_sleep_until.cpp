#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>




int main(int argc, char const *argv[])
{
    //sleep for time, say 2 seconds
    int timer1 = 2;
    std::cout << "sleeping for: "<< timer1 << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(timer1));
    std::cout << "Awake!" << std::endl;

    //sleep until a specific time point
    std::chrono::system_clock::time_point LTime = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point wakeUpTime = LTime + std::chrono::seconds(5);
    //convert it to time_t

    std::time_t LTime_t = std::chrono::system_clock::to_time_t(LTime);
    std::time_t wakeUpTime_t = std::chrono::system_clock::to_time_t(wakeUpTime);

    //convert time_t to local time

    std::tm* LTime_ = std::localtime(&LTime_t);
    std::tm* LocalTime = std::localtime(&wakeUpTime_t);
    LocalTime->tm_sec += 5;
    std::cout << "current time: " << std::put_time(LTime_, "%H:%M:%S") 
                <<" sleeping until " << std::put_time(LocalTime, "%H:%M:%S") << std::endl;
    std::this_thread::sleep_until(wakeUpTime);
    std::cout << "Awake!" << std::endl;



    return 0;
}
