//author: Usef Elbedwehy
//date: Mon 26 Aug 2024
//@session: 06
//@topic: OOP2 Part1
//@brief: Conversion

#include <iostream>
class Complex{
    private:
        int real;
        float img;
        std::string name;

    public:
        Complex():real(0),img(0.0f){
            std::cout << "The Complex constructor is called" << std::endl;
        }
        Complex(int r,float f,std::string s):real(r),img(f),name(s){
            std::cout << "The Complex constructor is called" << std::endl;
        }
        ~Complex(){
            std::cout << "The Complex destructor is called" << std::endl;
        }
        operator int(){
            return real;
        }
        operator std::string(){
            return name;
        }



};



int main(){

    Complex C1(3,4.5f,"Usef");

    int r1=C1;
    std::cout << "real: " << r1 << std::endl;

    std::string s1=C1;
    std::cout << "string: " << s1 << std::endl;

    return 0;
}