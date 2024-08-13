#include <iostream>
#include <algorithm>
//author: Usef Elbedwehy
//date: Tue 13 Aug 2024 
//@session: 01
//@topic: introduction to cpp
//@brief: (second task) -> maximum number between three values

int main(){

    int a = 0;
    int b = 0;
    int c = 0;

    std::cout << "Enter the 3 numbers: ";
    std::cin >> a >> b >> c;

    // std::cout << "The max number is: " << (a>b ? (a>c ? a : c) : (b>c ? b : c)) << "\n";

    int max_num = std::max({a,b,c});
    std::cout << "The max number is: " << max_num << std::endl;

    return 0;
}