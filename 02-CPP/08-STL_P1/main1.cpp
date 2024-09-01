//author: Usef Elbedwehy
//date: Sun 01 Sep 2024
//@session: 08
//@topic: OOP
//@brief: 0-3-5 rules

#include <iostream>
#include <string.h>
class String{

    private:
        char* str;
        int size;

    public:
    //01-default constructor
    String(): str(nullptr),size(0) {
        std::cout << "Default constructor" << std::endl;
    }
    //02-Parameterized constructor
    String(const char* s): size(strlen(s)),str(new char[size + 1]){
        std::cout << "Parameterized constructor" << std::endl;
        strcpy(str,s);
    }
    //03-Copy constructor
    String(const String& SS): size(SS.size), str(new char[size + 1]){
        //copy
        strcpy(str, SS.str);
        //print
        std::cout << "Copy constructor" << std::endl;
    }
    //04-Copy assignment operator 
    String& operator=(const String& RS){
        if(&RS != this){
            delete[] str;
            size = RS.size;
            str = new char[size + 1];
            strcpy(str,RS.str);

        }
        std::cout << "----Copy assignment operator----" << std::endl;
        return *this;

    }
    //05-Move constructor
    String(String&& SS): size(SS.size),str(SS.str){
        SS.size = 0;
        SS.str = nullptr;
        //print
        std::cout << "Move constructor" << std::endl;
    }
    //06-Move assignment operator 
    String& operator=(String&& RR){
        if(this != &RR){
            delete[] str;
            this->size = RR.size;
            this->str =  RR.str;
            RR.str = nullptr;
            RR.size = 0;
        }
        std::cout << "----Move assignment operator----" << std::endl;
        return *this;
    }
    //07-destructor
    ~String(){
        delete[] str;
        std::cout << "Default destructor" << std::endl;
    }

    void func(){
        std::cout << str << std::endl;
    }

};

int main(){

    String t1("Ahmed");
   

    // // // move constructor
    //  String t2(std::move(t1));
    // t2.func();
    // //t1.func();

    // // move assignment
    String t3;
    t3 = std::move(t1);

    t3.func();
    //t1.func();

    std::cout << "END" << std::endl;
    return 0;
}