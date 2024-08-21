//author: Usef Elbedwehy
//date: Sun 18 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: (5th task) -> ﬁnd the even and odd numbers in the array

#include <iostream>

void find_even_odd(int* arr1,int size1){

    std::cout << "TYPE " << " Index " << " Number"<< std::endl;  
    for(int i=0;i<size1;i++){
        if(arr1[i]%2 == 0){
            std::cout << "EVEN    " << i << "      " << arr1[i];
        }else{
            std::cout << "ODD     " << i << "      " << arr1[i];
        }
        std::cout << std::endl;
    }



}

#include <iostream>
//01-string
// int main(){

//     std::string my_name = "Usef Elbedwehy";

//     std::cout << my_name.substr(0) << std::endl;


//     return 0;
// }