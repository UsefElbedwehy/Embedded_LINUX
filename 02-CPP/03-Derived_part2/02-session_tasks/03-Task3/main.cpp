//author: Usef Elbedwehy
//date: Sun 18 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: (3nd task) -> delete number in array

#include <iostream>

void delete_number(int* arr,int arr_size,int delete_num){

    int index = 0;
    int check=0;
    if(arr_size == 0){
        std::cout << "Empty array." <<std::endl;
    }
    else{
        for(int i=0;i<arr_size;i++){
            if(delete_num == arr[i]){
                index = i;
                check = 1;
                break;
            }
        }
        if(check == 0)
        {
            std::cout << "Number not found....Deletion failed. " << std::endl;
        }else{
                for(int i=index;i<arr_size-1;i++){
                arr[i] = arr[i+1];
                }
                arr[arr_size-1] = 0;
                std::cout << "Deletion complete." << std::endl;
            }
        

    }



}

int main(){

    int arr[] = {1,2,3,4,9,8,7,6,5,10};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete_number(arr,size,8);

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}