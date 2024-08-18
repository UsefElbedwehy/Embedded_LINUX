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

int main(){

    int arr[] = {1,2,3,4,9,8,7,6,5,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    find_even_odd(arr,size);

    return 0;
}