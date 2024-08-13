#include <iostream>

int main(){

    int number = 0;
    int acc = 0;
    std::cout << "Enter digits: " ;
    std::cin >> number;

    while(number != 0){
        acc += number%10;
        number /= 10;
    } 
    std::cout << "The sum is: " << acc << std::endl;;


    return 0;
}