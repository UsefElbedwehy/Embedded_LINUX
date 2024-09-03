//author: Usef Elbedwehy
//date: Mon 02 Sep 2024
//@session: 08
//@topic: OOP
//@brief: inheritance

#include <iostream>

class Base1{
    private:
        int xbase1;
    public:
        void func(){
            std::cout << "Base1..." << std::endl;
        }

};

class Base2{
    private:
        int xBase2;
    public:
        void func(){
            std::cout << "Base2..." << std::endl;
        }

};

class Child: public Base1,public Base2{
    private:
        int xchild;
    public:
        void func(){
            std::cout << "Child" << std::endl;
        }
};


int main(){

    Child C2;
    C2.func();
    C2.Base1::func();
    C2.Base2::func();

    return 0;
}