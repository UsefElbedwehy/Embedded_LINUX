#include <iostream>
#include <vector>


// int g;
int main(){

    // std::cout << "Hello world!" << std::endl;

    // int i;
    // std::cout << "enter the number: ";
    // std::cin >> i;
    // std::cout << std::hex << "the number is " << i << std::endl;

    // unsigned char c;
    // std::cout << "enter the char: ";
    // std::cin >> c;
    // std::cout << "the char is " << c << std::endl;

    // std::string s;
    // std::cout << "enter the string: ";
    // std::cin >> s;
    // std::cout << "the string is " << s << std::endl;

    // double d;
    // std::cout << "enter the double: ";
    // std::cin >> d;
    // std::cout << "the double is " << d << std::endl;

    // float f;
    // std::cout << "enter the float: ";
    // std::cin >> f;
    // std::cout << std::showpoint << std::showpos << std::showbase << "the float is " << f << std::endl;

    // bool b;
    // std::cout << "enter the bool: ";
    // std::cin >> b;
    // std::cout << std::boolalpha << "the bool is " << b << std::endl;

    // bool bb;
    // std::cout << "enter the bool: ";
    // std::cin >> bb;
    // std::cout << std::noboolalpha << "the bool is " << bb << std::endl;
   
    // int g;
    // std::cout << std::dec << "the number is " << g << std::endl;

    int array[5]= {9,8,7,4,3};

    for(int i : array){
        std::cout << i << " " ;
    }
    std::cout << "\n";

    return 0;
 }