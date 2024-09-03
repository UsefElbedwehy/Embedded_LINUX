//author: Usef Elbedwehy
//date: Mon 02 Sep 2024
//@session: 08
//@topic: OOP
//@brief: inheritance

#include <iostream>

class Base{
    private:
    int xbase;
    public:
    Base(){

    }
    ~Base(){

    }
    void func(){
        std::cout << "Base" << std::endl;
    }

};

class Child1: public Base{
    private:
    int xchild1;
    public:
    Child1(){

    }
    ~Child1(){

    }
    void func(){
        std::cout << "Child1..." << std::endl;
    }

};

class Child2: public Child1{
    private:
    int xchild2;
    public:
    Child2(){

    }
    ~Child2(){

    }
    void func(){
        std::cout << "Child2" << std::endl;
    }

};


int main(){

    Child2 C2;
    C2.func();
    C2.Child1::func();
    C2.Base::func();

    return 0;
}