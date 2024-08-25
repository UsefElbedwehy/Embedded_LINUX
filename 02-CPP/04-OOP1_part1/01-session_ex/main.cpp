#include <iostream>

// void func(){
//     std::cout << "Hello World!" << std::endl;
// }

// int main(){

//     func();



//     return 0;
// }
// class Greeting
// {
// private:
//     /* data */
// public:
//     Greeting(/* args */);
//     ~Greeting();
//     void func()
//     {
//         std::cout << "Hello World!" << std::endl;
//     }
// };

// Greeting::Greeting(/* args */)
// {
// }

// Greeting::~Greeting()
// {
// }


// int main(){

//     Greeting G1;
//     G1.func();



//     return 0;
// }

// int main(){

//     int x = 0; //default initialzation
//     int y{};   //list initialzation
//     int u();   // NOT an initialization!
//     int v{0};  //list initialzation
//     int z(0);  //direct initialzation
//     int m{1};  //list initialzation
//     int n(1);  //direct initialzation

//     std::cout << "x = 0:"<< x <<
//     " y{}:" << y <<
//     " u():" << u <<
//     " v{0}:" << v <<
//     " z(0):" << z <<
//     " m{1}:" << m <<
//     " n(1):" << n 
//     << std::endl;


//     return 0;
// }
/////////////////////////////////////////////////////////////////
// enum Traffic{
//     RED,
//     YELLOW,
//     GREEN
// };
// int main()
// {
//     Traffic T1=YELLOW;
//     std::cout << T1 << std::endl;
//     std::cout << RED << std::endl;
//     std::cout << YELLOW << std::endl;
//     std::cout << GREEN << std::endl;
//     int color = GREEN;
//     std::cout << color << std::endl;
//     //T1 = 2;     //Error cannot convert enum to int
//     return 0;
// }

// enum class MyClass {
//     RED,
//     YELLOW,
//     GREEN
//  };

// int main(){

//     MyClass C1;

//     std::cout << static_cast<int>(MyClass::GREEN) << std::endl;


//     return 0;
// }

// struct Data{
//     int x;
//     int y;
//     void func(){
//         std::cout << "Hello World!" << std::endl;
//     }
// };

// int main(){

//     Data d;
//     d.func();

//     return 0;
// }

// //////////////////////////////////////////////////////////////////
// ///const in class

// class Animals{
//     private:
//         int var1;
//         mutable int var2;
//         int var3 = 10;
//         const float var4=102.2f;
//         const int var5;
//         const float var6;
//         const int var7 = 20;
//         int &var8 = var1;

//     public:
//         Animals(): var5(99) , var6(88) {

//         }
//         ~Animals(){
            
//         }
//         void eat(int arg) const {

//             //1- u can create local var
//             int const a = 10;
//             int b = 11;
//             //2- local var can be modified
//             b = 12;
//             //3- arguments can be modified
//             arg = 100;
//             //4- u cant change or access any member var
//             //var1 = 1212;    //error
//             //4-1- u can change them if they are mutable only
//             var2 = 200;    //mutable 
//             //5- refrence can be accessed
//             var8 = 10;


//         }
//         void speak(){
//             std::cout << "Speak" << std::endl;
//         }
// };



// int main(){

//     //6- const instance can call const func
//     const Animals A1;
//     A1.eat(44);
//     //A1.speak();       //Error
//     //7- non-const instance can call const or non-const functions
//     Animals A2;
//     A2.eat(66);
//     A2.speak();


//     return 0;
// }

// //////////////////////////////////////////////////////////////////
// ///static member in class

class Data {
    private:
        int value;
        static int counter; // 1- must be defined outside the class
        static int counter2; // 1- must be defined outside the class
    public:
    int x;
        static int counterp;  // 1- must be defined outside the class
        Data(){
            counter++;
        }
        void print(){
            std::cout << counter << std::endl;
            value =0;
        }
        //// static method
        static void showCounts(){
           // value =0;         //// 1- Error: can not access member
            counter = 0;        //// 2- can access static member
            int local_x;        //// 3- can create local var
            local_x = 1200;

        }

};
int Data::counter = 100;   // 1.1- in .data section
int Data::counter2 = 0;   // 1.2- in .bss section
int Data::counterp = 0;   // 1.3- in .bss section

int main(){

    Data D1;
    Data D2;
    Data D3;
    Data D4;
    Data D5;

    D1.print();
    D2.print();
    //Data::print();     // to be accessed must use static function

    Data::counterp = 100;   //2- public can be accessed with Data::counterp  
    D3.counterp = 90;       //3- public can be accessed with object

    return 0;
}








