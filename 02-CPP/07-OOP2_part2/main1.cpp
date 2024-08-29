//author: Usef Elbedwehy
//date: Wed 28 Aug 2024 
//@session: 07
//@topic: OOP2 PART2
//@brief: copy constructor - copy assignment - destructor 

#include <iostream>
#include <string.h>
class String{
    private:
        char* str;
        int size;
    public:
        //default constructor
        String()/*Initializer list*/: size(0), str(nullptr) {
            std::cout << "Default constructor is called." << std::endl;
        }
        //constructor
        String(const char* s)/*Initializer list*/: size(strlen(s)), str(new char(size + 1)) {
            std::cout << "Parameterized constructor is called." << std::endl; 
            strcpy(str, s);
        }
        //copy constructor
        String(const String& copy): size(copy.size), str(new char(copy.size + 1)){
            std::cout << "Copy constructor is called." << std::endl; 
            strcpy(str , copy.str);
        }
        String& operator=(const String& Bridge){
            if(&Bridge == this){
                return *this;
            }
            
            delete[] str;
            this->size = Bridge.size;
            this->str = new char(size + 1);
            strcpy(this->str,Bridge.str);  
            return *this;
        }

        void func()  {
            std::cout << "str: " << (str ? str : "null") << std::endl;
        }
        void set1stchar(char value){
            if (str && size > 0) {
            str[0] = value;
            }
        }
        
        ~String(){
            std::cout << "Destructor is called." << std::endl; 
            delete[] str;
        }


};

int main(){

    char array[] = "Hello";
    String S1(array);
    String S2(S1);

    S1.func();
    S2.func();
    S2.set1stchar('M');
    S2 = S2;
    S1.set1stchar('A');
    S1.func();
    S2.func();

    return 0;
}