#include <iostream>
//author: Usef Elbedwehy
//date: Tue 13 Aug 2024 
//@session: 01
//@topic: introduction to cpp
//@brief: (4th task) -> decide the letter is vowel or not

int main(){

    char a = '0';
    char vowel[5]={'a','o','u','e','i'};
    bool IsVowel = false;
    std::cout << "Enter the letter: ";
    std::cin >> a;
    
    a = std::tolower(a);

    for(char i : vowel){
        if(a == i){
            IsVowel = true;
            break;
        }
    }
    if(IsVowel == false){
        std::cout << "Not vowel letter ;(" << std::endl;
    }
    else{
        std::cout << "VOWEL LETTER ;)" << std::endl;
    }
    

    return 0;
}