//author: Usef Elbedwehy
//date: Wed 14 Aug 2024
//@session: 02
//@topic: Derived Datatypes
//@brief: Derived Datatypes with Moatasem Elsayed
//@Content: Functions - Array - pointers - References - auto - Casting - Lambda - Const vs constexpr
#include <iostream>
//01-string
// int main(){

//     std::string my_name = "Usef Elbedwehy";

//     std::cout << my_name.substr(0) << std::endl;


//     return 0;
// }

//02-Function overloading

// int multiply(int a ,int b){
//     std::cout << "int multiply(int a ,int b)" << std::endl;
//     return a*b;
// }

// float multiply(float a ,float b){
//     std::cout << "float multiply(float a ,float b)" << std::endl;
//     return a*b;
// }
// int main(){

//     std::cout <<  multiply(5,8) << std::endl;
//     std::cout <<  multiply(5.0f,8.0f) << std::endl;

//     return 0;
// }

// 03-insert

// int main(){

//     std::string name = "Usef Elbedwehy";
//     name.insert(name.begin(),3,'t');

//     std::cout << name << std::endl;

//     return 0;
// }

// 04-arrays
// int main(){

//     int numbers[]={[0]=1,[1]=9};
//     int matrix[3][3] = {
//         [0]={1,2,3},
//         [1]={7,5,4},
//         [2]={3,7,5}
//     };
//     int size = sizeof(numbers)/sizeof(numbers[0]);
//     std::cout << size << ' ' << matrix[0][2] << ' ' << numbers[1] << std::endl;

//     return 0;
// }

// pointers

// int main(){

//     int x =10;
//     int *ptr1 = NULL;
//     int *ptr2 = nullptr;
//     int *ptr3 = &x;

//     std::cout << "x:  "  << x << std::endl;
//     std::cout << "&x: "  << &x << std::endl;

//     std::cout << "ptr1: " <<  ptr1 << std::endl;
//     //std::cout << *ptr1 << std::endl;
//     std::cout << "&ptr1: " << &ptr1 << std::endl;
    
//     std::cout <<  "ptr2: " <<  ptr2 << std::endl;
//     //std::cout <<  "*ptr2: " << *ptr2 << std::endl;
//     std::cout <<  "&ptr2: " << &ptr2 << std::endl;

//     std::cout <<  "ptr3: " << ptr3 << std::endl;
//     std::cout <<  "*ptr3: " << *ptr3 << std::endl;
//     std::cout <<  "&ptr3: " << &ptr3 << std::endl;
    
//     std::cout <<  "NULL: " << NULL << std::endl;


//     return 0;
// }

// 05-pass by pointer
// void foo(int *ptr){
//     std::cout << *ptr << std::endl;
// }

// int main(){

//     int x = 50;
//     foo(&x);

//     return 0;
// }

// dynamic memory allocation
// int main(){

//     int x = 10;
//     int* ptr = new int[5];
//     ptr = &x; 

//     std::cout << *ptr << std::endl;

//     return 0;
// }

// int main(){

//     int* a = NULL;
//     char* y =NULL;

//     a = reinterpret_cast<int*>(y);

//     return 0;
// }
// int main(){

//     int a = 100;
//     char y ='a';

//     a = static_cast<int>(y);

//     return 0;
// }
// int main(){

//     const int x =100;

//     int* d = const_cast<int*>(&x);

//     return 0;
// }
int main(){

    std::cout << "Hello Usef" << std::endl;
    std::cout << "Hello Usef" << std::endl;
    std::cout << "Hello Usef" << std::endl;
    std::cout << "Hello Usef" << std::endl;
    std::cout << "Hello Usef" << std::endl;

    return 0;
}