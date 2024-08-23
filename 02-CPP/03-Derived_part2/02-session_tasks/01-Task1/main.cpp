//author: Usef Elbedwehy
//date: Sun 18 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: (first task) -> create a function to ﬁnd the maximum number of array

#include <iostream>
#include <algorithm>  // Include for std::max_element

int max_number(int* arr, int arr_size){

    int local_max_number = arr[0]; // assume max is the first element

    if(arr_size == 0){
    std::cout << "Array is empty." << std::endl;
    return -1 ; // return -1 as status for empty array
    }
    for(int i=1;i<arr_size;i++){
        if(local_max_number < arr[i]){
            local_max_number = arr[i]; // update max
        }
    }
    return local_max_number;
}

int main(){

    int arr[8] = {1,23,4,5,6,767,543,768};
    int size = sizeof(arr)/sizeof(arr[0]); // calc size of array
    std::cout << "The max number in the array is: " << max_number(arr,size) << std::endl;
    //thinking in cpp
    std::cout << "The max number: " << *std::max_element(std::begin(arr),std::end(arr)) << std::endl;


    return 0;
}