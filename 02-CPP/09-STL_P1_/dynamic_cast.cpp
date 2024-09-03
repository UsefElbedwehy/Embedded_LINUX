//author: Usef Elbedwehy
//date: Wed 04 Sep 2024
//@session: 08
//@topic: OOP
//@brief: inheritance
#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void show() override {
        std::cout << "Derived2 class" << std::endl;
    }
};
int main() {
    //01
    Base* base_ptr = new Derived;

    Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);

    if (derived_ptr == nullptr)
    {
        std::cout << "Failed" << std::endl;
    }else{
        derived_ptr->show();
    }
    delete base_ptr;

    //02
    Base* base_ptr_2 = new Derived2;
    Derived* derived_ptr_2 = dynamic_cast<Derived*>(base_ptr_2);
    if (derived_ptr_2 == nullptr)
    {
        std::cout << "Failed" << std::endl;
    }else{
        derived_ptr_2->show();
    }
    delete base_ptr_2;


    return 0;
}
