#include <iostream>
int y = 0;
void printMyName(){
    y++;
    std::cout << "Hello Usef" << std::endl;
    y++;
}

int main(){

    int x = 100;
    y++;
    x = 300;
    std::cout << "x = " << x << std::endl;

    printMyName();
    y++;
    x = 400;
    std::cout << "x = " << x << std::endl;

    return 0;
}