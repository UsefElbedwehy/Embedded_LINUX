#include <iostream>
#define end 0

constexpr int square(int n){
    
    if(n>20){
        //std::cout << n << std::endl;
    }
    return n*n;
}



int main(){
    int xoffset = 100;
    int yoffset = 300;
    int x=90;
    int y=70;
    // auto fn = [offset](int number){
    //     std::cout << "The number is: " << number << std::endl;
    //     std::cout << "The offset is: " << offset << std::endl;  
    //     std::cout << "The sum is: " << number+offset << std::endl;
    // };
    // fn(12);

    // [offset](int number){
    //     std::cout << "The number is: " << number << std::endl;
    //     std::cout << "The offset is: " << offset << std::endl;  
    //     std::cout << "The sum is: " << number+offset << std::endl;
    // }(12);

    // [=](int number){
    //     //offset = 300;   //error: assignment of read-only variable ‘offset’
    //     std::cout << "The number is: " << number << std::endl;
    //     std::cout << "The offset is: " << offset << std::endl;  
    //     std::cout << "The sum is: " << number+offset << std::endl;
    // }(12);

    // [&](int number){
    //     offset = 300;   
    //     std::cout << "The number is: " << number << std::endl;
    //     std::cout << "The offset is: " << offset << std::endl;  
    //     std::cout << "The sum is: " << number+offset << std::endl;
    // }(12);

    // [&offset](int number){
    //     offset = 300;   
    //     std::cout << "The number is: " << number << std::endl;
    //     std::cout << "The offset is: " << offset << std::endl;  
    //     std::cout << "The sum is: " << number+offset << std::endl;
    // }(12);
    // // [&xoffset,yoffset](int x,int y){
    // //     xoffset = 333;  
    // // //     yoffset = 500;  //error: assignment of read-only variable ‘yoffset’
    // //     std::cout << "The x is: " << x << std::endl;
    // //     std::cout << "The xoffset is: " << xoffset << std::endl;  
    // //     std::cout << "The y is: " << y << std::endl;
    // //     std::cout << "The yoffset is: " << yoffset << std::endl; 
    // // }(12,21);   

    // [](){
    //     std::cout << "Hello Usef! "<<std::endl;
    // }(); 
    
    // auto fn = [](auto a ,auto b){
    //     return a+b;
    // };

    // std::cout << typeid((5,6)).name() << std::endl; 
    // std::cout << typeid(fn(5.5,6.7)).name() << std::endl; 
    // std::cout << typeid(fn(5.8f,6.7f)).name() << std::endl; 
    // std::cout << typeid(fn('d','s')).name() << std::endl; 
    
    //     [=](int number) mutable{
    //     xoffset = 300;   //error: assignment of read-only variable ‘offset’
    //     std::cout << "The number is: " << number << std::endl;
    //     std::cout << "The xoffset is: " << xoffset << std::endl;  
    //     std::cout << "The sum is: " << number+xoffset << std::endl;
    // }(12);
    // std::cout << "The xoffset is: " << xoffset << std::endl; 

    // [&xoffset = y, yoffset = x](int a,int b) mutable{
    //     //xoffset = 300;   //error: assignment of read-only variable ‘offset’
    //     std::cout << "The xoffset is: " << xoffset << std::endl;
    //     std::cout << "The y is: " << a << std::endl;
    //     std::cout << "The yoffset is: " << yoffset << std::endl;
    //     std::cout << "The x is: " << b << std::endl; 
    // }(x,y);
    // std::cout << "The xoffset is: " << xoffset << std::endl;
    // std::cout << "The y is: " << y << std::endl;
    // std::cout << "The yoffset is: " << yoffset << std::endl;
    // std::cout << "The x is: " << x << std::endl; 

    // // const int var1 = rand();
    // // // constexpr int var2 = rand();      //error 
    // // constexpr int var2 = 30; 

    // const int var3 = square(y);
    // std::cout << var3 << std::endl;

    constexpr int var3 = square(30);
    std::cout << var3 << std::endl;

    return end;
}