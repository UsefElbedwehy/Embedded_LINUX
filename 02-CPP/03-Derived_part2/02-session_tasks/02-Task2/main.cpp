//author: Usef Elbedwehy
//date: Sun 18 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: (2nd task) -> create a function to search to the number in the array which number is taken from user

#include <iostream>

void search_number(int* arr , int arr_size){
    int number_to_search = 0;
    int check=0;
    std::cout << "Enter the number to search: "<< std::endl;
    std::cin >>  number_to_search;
    if(arr_size == 0){
        std::cout << "Empty array." <<std::endl;
    }
    else{
        for(int i=0;i<arr_size;i++){
            if(number_to_search == arr[i]){
                std::cout << "Number is found in array." << std::endl;
                std::cout << "Number index is :" << i << std::endl;
                check = 1;
                break;
            }
    }
    }
    if(check == 0){
        std::cout << "Number is not found."<< std::endl;
    }
    
}


int main(){

    int arr[] = {1,2,3,4,9,8,7,6,5,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    search_number(arr,size);

    return 0;
}