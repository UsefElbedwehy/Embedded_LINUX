//author: Usef Elbedwehy
//date: Mon 02 Sep 2024
//@session: 08
//@topic: OOP
//@brief: 0-3-5 rules
#include <iostream>

//                               ClassA
//                                  |
//                     ---------------------------
//                     |                         |
//                  ClassB                    ClassC
//                     |                         |
//                     ---------------------------
//                                  |
//                               ClassD



class ClassA{
    private:
    
    public:
    ClassA(){
        std::cout << "ClassA Constructor." << std::endl;
    }
    ~ClassA(){
        std::cout << "ClassA Destructor." << std::endl;
    }
    void printClassA(){
         std::cout << "ClassA print method." << std::endl;
    }

};

class ClassB: virtual public ClassA{
    private:
   
    public:
    ClassB(){
        std::cout << "ClassB Constructor." << std::endl;
    }
    ~ClassB(){
        std::cout << "ClassB Destructor." << std::endl;
    }

};

class ClassC: virtual public ClassA{
    private:

    public:
    ClassC(){
        std::cout << "ClassC Constructor." << std::endl;
    }
    ~ClassC(){
        std::cout << "ClassC Destructor." << std::endl;
    }

};

class ClassD: virtual public ClassB ,virtual public ClassC {
    private:
    
    
    public:
    ClassD(){
        std::cout << "ClassD Constructor." << std::endl;
    }
    ~ClassD(){
        std::cout << "ClassD Destructor." << std::endl;
    }

};
int main(){

    ClassD D1;

    D1.ClassC::printClassA();
    D1.printClassA();


    return 0;
}