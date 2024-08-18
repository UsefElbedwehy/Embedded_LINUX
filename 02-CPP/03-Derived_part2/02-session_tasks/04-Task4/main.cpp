//author: Usef Elbedwehy
//date: Sun 18 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: (4th task) -> merge two arrays together

#include <iostream>

void merge_array(int *arr1, int *arr2 ,int *merged_arr ,int arr1_size, int arr2_size){

    if ((arr1_size == 0) && (arr1_size == 0))
    {
        std::cout << "Empty array. :(" << std::endl;
    }else if(arr1_size == 0){
            //No merge done
            std::cout << "1st array is empty. :(" << std::endl;

    
    }else if(arr2_size == 0){
            //No merge done
            std::cout << "2nd array is empty. :(" << std::endl;
    }else{

    int size_all = (arr1_size + arr2_size);

    std::cout << "Array: " ;
    for(int i=0;i<size_all;i++){
        if(i < arr1_size){
            merged_arr[i] = arr1[i];
        }
        else{
            merged_arr[i] = arr2[i-arr1_size];
        }
    std::cout << merged_arr[i] << " " ;
    }
    std::cout << std::endl;
    std::cout << "Merge done! " << std::endl;
    }

}

int main(){


    int arr1[] = {1,2,3,4,9,8,7,6,5,10};
    int arr2[] = {44,33,21,54,6};

    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int size_all = (size1 + size2);
    int arr3[size_all] = {0};

    merge_array(arr1,arr2,arr3,size1,size2);

    // std::cout << "Array: " ;
    // for(int i=0;i<size_all;i++){
    //     if(i < size1){
    //         arr3[i] = arr1[i];
    //     }
    //     else{
    //         arr3[i] = arr2[i-size1];
    //     }
    // std::cout << arr3[i] << " " ;
    // }
    // std::cout << std::endl;
    // std::cout << "Merge done! " << std::endl;
    


    return 0;
}