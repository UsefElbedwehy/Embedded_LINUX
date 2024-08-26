#include <iostream>

class LCD{
    private:
        int cursor;
        std::string name;

    public:
        LCD():cursor(0),name("Default.") {
            std::cout << "LCD constructor is called." << std::endl;
        }
        LCD(int c, std::string n): cursor(c),name(n) {
            std::cout << "LCD constructor is called." << std::endl;
        }
        ~LCD(){
            std::cout << "LCD destructor is called." << std::endl;
        }
        int operator++(int x){
            int temp = this->cursor;
            this->cursor++;
            return temp;
        }
        void operator++(){
            this->cursor++;
        }
        int getter(){
            return cursor;
        }

};



int main(){

    //LCD D1( 0 , "Hello World!");
    LCD D1;
    int var1 = 100;

    D1++;                   // D1.operator++(int)
    D1++;
    D1++;
    D1++;
    ++D1;                   // D1.operator++(void)
    // cursor = 4
    std::cout << D1.getter() << std::endl;

    return 0;
}