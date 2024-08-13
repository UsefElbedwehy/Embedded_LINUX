#include <iostream>

//author: Usef Elbedwehy
//date: Tue 13 Aug 2024 
//@session: 01
//@topic: introduction to cpp
//@brief: (first task) -> Create a table for AscII code

int main()
{
    char c = '0';

    std::cout << "ASCII table: " << std::endl; 

    for(int i=48;i < 127;i++,c++){
        if(i < 100){
            std::cout << "              |  " << i << " | " << c << " |\n" ; 
        }else{
            std::cout << "              | " << i << " | " << c << " |\n" ; 
        }
       
    //    c++;
    }

    std::cout << "\n"; 

    return 0;
}




