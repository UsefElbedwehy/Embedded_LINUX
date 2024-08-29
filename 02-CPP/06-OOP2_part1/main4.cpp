//author: Usef Elbedwehy
//date: Mon 26 Aug 2024
//@session: 06
//@topic: OOP2 Part1
//@brief: Implicit and explicit Conversion

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
        explicit Complex(int r):real(r){
            std::cout << "The Complex constructor is called. Complex(int r)" << std::endl;
        }
        Complex(int r,float f,std::string s):real(r),img(f),name(s){
            std::cout << "The Complex constructor is called" << std::endl;
        }
        ~Complex(){
            std::cout << "The Complex destructor is called" << std::endl;
        }

};



int main(){

    // // //Complex C1(3,4.5f,"Usef");
    //Complex C2=2; //Complex(int r) will be called as Complex(2)
    // // we add explicit keyword to the func decleration to prevent this from happening  
    Complex C1(2);  //work
    //Complex C2=2; // do not

    return 0;
}