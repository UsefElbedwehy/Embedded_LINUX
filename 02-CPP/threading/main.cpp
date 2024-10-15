#include <chrono>
#include <iostream>
#include <thread>

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findOdd(ull start, ull end){
    for(int i = start ; i <= end ; i++){
        if (i%2 != 0){
            oddSum+=i;
        } //if
    }//for
}//findOdd

void findEven(ull start, ull end){
    for(int i = start ; i <= end ; i++){
        if (i%2 == 0){
            evenSum+=i;
        } //if
    }//for
}//findEven



int main(int argc, char const *argv[])
{
    ull start=0, end=1900000000;

    auto startTime = std::chrono::high_resolution_clock::now(); 

    std::thread t1(findEven,start, end);
    std::thread t2(findOdd,start, end);
    
    findEven(start, end);
    findOdd(start, end);
    
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "Odd: "  << oddSum << std::endl;
    std::cout << "Even: " << evenSum << std::endl;

    std::cout << "Duration in sec: " << duration.count()/1000000 << std::endl;

    return 0;
}
