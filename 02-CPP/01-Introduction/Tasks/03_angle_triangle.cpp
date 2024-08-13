#include <iostream>
//author: Usef Elbedwehy
//date: Tue 13 Aug 2024 
//@session: 01
//@topic: introduction to cpp
//@brief: (third task) -> RIGHT angle triangle

void RightAngled(void){
    std::cout << "It is --right(90)-- angled triangle. ;)" << std::endl;
}

int main(){

    int a = 0;
    int b = 0;
    int c = 0;

    std::cout << "Enter the 3 angles of the triangle: ";
    std::cin >> a >> b >> c;

    if(a == 90){
        RightAngled();
    }else if (b == 90)
    {
        RightAngled();
    }else if(c == 90){
        RightAngled();
    }else{
        std::cout << "Igt is not right angled triangle. ;(" << std::endl;
    }
    

    return 0;
}