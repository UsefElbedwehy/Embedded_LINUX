//author: Usef Elbedwehy
//date: Wed 28 Aug 2024 
//@session: 07
//@topic: OOP2 PART2
//@brief: (lvalue/rvalue) 
#include <iostream>
int &funref(){
    static int ref = 10;
    return ref;
}

int funint(){
    static int varint = 20;
    return varint;
}
void funi(int num) 
{
    std::cout << num << std::endl;
}
void funr(int &num) 
{
    std::cout << num << std::endl;
}
void funrc(const int &num) 
{
    std::cout << num << std::endl;
}
int main(){
    // 01------------------------------------------------------------
    funref() = 30;      // funref() is Lvalue
    std::cout << "funref(): " << funref() << std::endl;  // output: 30   (ref = 30)

    //funint() = 40;    //Error : it returns 20 and it will be like 20 = 30 XXXXXX
    // funref() is Rvalue as it returns pure rvalue (temporary value)

    // 02------------------------------------------------------------
    // note: continous on the previous, consider the prevoius numbers in the outputs
    int Lval = funref(); 
    std::cout << "funref(): " << funref() << std::endl;  // output: 30   ref = 30
    std::cout << "Lval    : " << Lval << std::endl;  // output: 30   (Lval = ref) ,since ref = 30 ,then Lval = 30 ; 

    Lval = 40;
    funref() = Lval; 
    std::cout << "funref(): " << funref() << std::endl;  // output: 40      ref = Lval=40   
    std::cout << "Lval    : " << Lval << std::endl;  // output: 40

    Lval = funint();   // output: 20        funint returns 20 then Lval = 20;
    funref() = Lval;   // output: 20        ref = 20;
    std::cout << "funref(): " << funref() << std::endl;  // output: 20      
    std::cout << "Lval    : " << Lval << std::endl;  // output: 20

    // 03------------------------------------------------------------
    // note: continous on the previous, consider the prevoius numbers in the outputs
    std::string name  = "Usef";
    std::string name2 = std::move(name);

    std::cout << name  << std::endl;  // output: empty 
    std::cout << name2 << std::endl;  // output: Usef 

    // 04------------------------------------------------------------
    // note: continous on the previous, consider the prevoius numbers in the outputs
    int var4 = 10;
    int &ref4 = var4;
    
    // T x
    funi(10);       // output: 10 
    funi(var4);     // output: 10 
    funi(ref4);     // output: 10 

    // T &x
    //funr(10);     //Error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    funr(var4);     // output: 10 
    funr(ref4);     // output: 10 

    // Const T & (can bind to temp value)
    funrc(10);      // output: 10 

    return 0;
}