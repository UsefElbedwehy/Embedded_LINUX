#include <iostream>
//author: Usef Elbedwehy
//date: Tue 13 Aug 2024 
//@session: 01
//@topic: introduction to cpp
//@brief: (5th task) -> multiplication table

int main(){

    int number=0;
    std::cout << "Enter the number: ";
    std::cin >> number;
    
    std::cout << "The multiplication table " << number << "of: " << std::endl;
    std::cout << "--------------" << std::endl; 
    for(int i=1;i<10;i++){
        if((i*number) < 10){
            std::cout << "| " << i << " x " << number << " = " << (i*number) << "  |" << std::endl; 
            continue;
        }
        std::cout << "| " << i << " x " << number << " = " << (i*number) << " |" << std::endl; 
    }
    std::cout << "--------------" << std::endl; 
    
    return 0;
}