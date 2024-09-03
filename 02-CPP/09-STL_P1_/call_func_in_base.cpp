//author: Usef Elbedwehy
//date: Tue 03 Sep 2024
//@session: 08
//@topic: OOP
//@brief: Inheritance
#include <iostream>
//Call function in Base
//---------------------------------------------------------------------------------------------------
//To create derived instance, a Base constructor will be called first then the derived one.         |
// last one u mentioned will call destructor first and so on                                        |
// -> Base constructor -> Derived constructor -> Derived destructor -> Base destructor              |
//      |                    |                        |                 |                           |
//      |                    --------------------------                 |                           |
//      |                                                               |                           |
//       ---------------------------------------------------------------                            |
//                                                                                                  |
//---------------------------------------------------------------------------------------------------
class Base{
    private:
        int Basex;
    public:
    Base(){
        std::cout << "Constructor Base." << std::endl;
    }
    ~Base(){
        std::cout << "Destructor Base." << std::endl;
    }
    void func(){
        std::cout << "Hello from the Base." << std::endl;
    }
};
class Derived: virtual public Base{
    private:
        int Derivedx;
    public:
    Derived(): Base(){
        std::cout << "Constructor Derived." << std::endl;
    }
    ~Derived(){
        std::cout << "Destructor Derived." << std::endl;
    }
    void func(){
        Base::func();
    }
};

int main(){

    Base B1;
    Derived D1;
    // B1.func();
    D1.func();

    return 0;
}