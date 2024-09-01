//author: Usef Elbedwehy
//date: Sun 01 Sep 2024
//@session: 08
//@topic: OOP
//@brief: 0-3-5 rules
//task: 01-Create Class behave like string/Integer totally

#include <iostream>
#include <string.h>
//01-1-class behave like String:
class String{

    private:
        char* str;  
        int   size;

    public:
    //friend << operator overloading
    friend std::ostream& operator<<(std::ostream& os,const String& S);
    //Default constructor
    String(): str(nullptr),size(0){
        std::cout << "Default constructor" << std::endl;
    }
    //Default destructor
    ~String(){
        delete[] str;
        std::cout << "Default destructor" << std::endl;
    }
    //Parameterized constructor
    String(const char* s): str(new char[strlen(s) + 1]), size(strlen(s)){
        std::cout << "Parameterized constructor" << std::endl;
        strcpy(str,s);
    }

    //Copy constructor
    String(const String& CS): str(new char[CS.size + 1]),size(CS.size){
        strcpy(str,CS.str);
        std::cout << "Copy constructor" << std::endl;
    }
    //Copy assignment operator
    String& operator=(String& RS){
        if(this != &RS){
            if(RS.str == nullptr){
                this->size = 0;
                this->str  = nullptr;
            }
            this->size = RS.size;
            delete[] str;
            strcpy(this->str,RS.str);
        }
        std::cout << "Copy assignment operator" << std::endl;
        return *this;
    }

    //Move constructor
    String(String&& MS): str(MS.str),size(MS.size){
        MS.str  = nullptr;
        MS.size = 0;
        std::cout << "Copy constructor" << std::endl;
    }
    //Move assignment operator
    String& operator=(String&& RR){
        if(this != &RR){
            this->str  = RR.str;
            RR.str     = nullptr;
            this->size = RR.size;
            RR.size    = 0;
        }
        std::cout << "Move assignment operator" << std::endl;
        return *this;
    }

};

class Integer{

    private:
        int number;

    public:
    //friend
    friend std::ostream& operator<<(std::ostream& os,const Integer& I);
        Integer():number(0){
            std::cout << "Default constructor." << std::endl;
        }
        Integer(int xnumber):number(xnumber){
            std::cout << "Parameterized constructor." << std::endl;
        }
        ~Integer(){
            std::cout << "Default Destructor." << std::endl;
        }
        //Integer operators overloading 
        //   pre/post++ pre/post-- 

        void operator=(int x){
        number = x;
        }

        void operator+=(int x){
        number = number + x;
        }
        void operator-=(int x){
        number = number - x;
        }
        void operator/=(int x){
        number = number / x;
        }
        void operator*=(int x){
        number = number * x;
        }
        void operator%=(int x){
        number = number % x;
        }

        int operator+(const Integer& I){
        return number + I.number;
        }
        int operator-(const Integer& I){
        return number - I.number;
        }
        int operator/(const Integer& I){
        return number / I.number;
        }
        int operator*(const Integer& I){
        return number * I.number;
        }
        int operator%(const Integer& I){
        return number % I.number;
        }

        //pre -- ++
        // --x or ++x
        int operator++(){
            return ++number;
        }
        int operator--(){
            return --number;
        }
        //post -- ++
        int operator++(int x){
            int temp = number;
            number++;
            return temp;
        }
        int operator--(int x){
            int temp = number;
            number--;
            return temp;
        }
};

// << operator overloading for String
std::ostream& operator<<(std::ostream& os,const String& S){
    os << S.str;
    return os;
}
// << operator overloading for Integer
std::ostream& operator<<(std::ostream& os,const Integer& I){
    os << I.number;
    return os;
}



int main(){


    // // // //01
    // // // // ! What’s Happening in Your Code:

    // // // // String user_name = "Usef Elbedwehy";:
    // // // //  -Temporary Object Creation: A temporary String object is created from the C-style string "Usef Elbedwehy" 
    // // // //      using the parameterized constructor.
    // // // //  -Copy Constructor: The temporary String object is then copied to the user_name object 
    // // // //      using the copy constructor because of the assignment (=) operator in the initialization.
    // // // //  -Destructor Call for the Temporary Object: After the copy is made, 
    // // // //      the temporary String object is destroyed, leading to the first destructor call.
    // String user_name = "Usef Elbedwehy";
    // // // // -The operator<< is called to print user_name, 
    // // // //      but since this is after the temporary object has already been destroyed, 
    // // // //      it works on the copied object (user_name).
    // std::cout << user_name << std::endl;

    // // // //02
    // // // //String name("Usef Elbedwehy");
    // // // //03
    // // // // String name2("Usef Elbedwehy");
    // // // // String name3(name2);
    // // // // std::cout << name3 << std::endl;

    //---------------------------------------for Integer class:---------------------------------
    Integer num1;
    Integer num2;
    Integer num3;


    num1=10;
    num2=90;

    num1 += 10;
    num2 -= 10;
    num1--;
    --num2;
    num3 = num2 + num1;         //num3.operator=(num2.operator(num1)) -> num3.operator=(int: num1.number+num1.mumber)

    std::cout << "number: " << num1 << std::endl;
    std::cout << "number: " << num2 << std::endl;
    std::cout << "number: " << num3 << std::endl;
    return 0;
}