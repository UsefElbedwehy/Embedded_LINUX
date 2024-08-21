//author: Usef Elbedwehy
//date: Sun 18 Aug 2024
//@session: 03
//@topic: derived part 2
//@brief: Simple Lambda: Write a lambda function to calculate the square of a given number.
#include <iostream>
#include <algorithm>
auto fn = [](int a){
        return a*a;
    };



int main() {
    
    int a{7};
    int arr[10] =  {8,9,5,7,1,2,6,3,4,10};
    std::cout << "The square of " << a << " is: " << fn(a) << std::endl;

    auto sort_arr = [&arr](bool IsAsc){
        if(IsAsc)
        {
            std::sort(std::begin(arr),std::end(arr));
            std::cout << "Ascending: ";
            for(int number : arr){
            std::cout <<  number << " " ;
            
        }
        std::cout << std::endl;
        }
        else{
            std::sort(std::begin(arr),std::end(arr),std::greater<int>());
            std::cout << "Decending: ";
            for(int number : arr){
            std::cout <<  number << " " ;
            
        }
        std::cout << std::endl;
        }
    };

    
    sort_arr(true);
    sort_arr(false);
    
 
    return 0;

}