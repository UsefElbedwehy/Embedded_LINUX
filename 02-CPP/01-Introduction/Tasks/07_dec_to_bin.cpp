// //author: Usef Elbedwehy
// //date: Wed 14 Aug 2024
// //@session: 01
// //@topic: introduction to cpp
// //@brief: (7th task) -> change from decimal to binary and vice versa
 #include <iostream>
// #include <math.h>
// int DecToBin(int Dec){
    
//     int Bin = 0;
//     int i = 8;

//     while(i != 0)
//     {
//         i--;
//         if(Dec == pow(2,i)){

//             Dec -= pow(2,i);
//             Bin = ((Bin*10) + 1);

//         }else if(Dec < pow(2,i)){

//             Bin = ((Bin*10) + 0);

//         }
//         else if(Dec > pow(2,i)){

//             Dec -= pow(2,i);
//             Bin = ((Bin*10) + 1);
            
//         }else{
            
//             Bin = ((Bin*10) + 0);

//         }
//     }

//     return Bin;

// }

// int BinToDec(int Bin){

//     int Dec = 0;
//     int i = 0;

//     while(Bin != 0)
//     {
//         Dec += ((Bin%10) * pow(2,i)) ;
//         Bin /= 10;
//         i++;
//     }

//     return Dec;
// }



// int main(){

//     bool IsDecimal = true;
//     int number = 0;
//     int representation = 0;
//     std::cout << "Enter 1 to change to binary, enter 0 to change to decimal: ";
//     std::cin >> IsDecimal;

//     if(IsDecimal == true)
//     {
//         //change into binary
//         std::cout << "Enter decimal number: ";
//         std::cin >> number;

//         //process
//         representation = DecToBin(number);

//         //output
//         std::cout << "The binary representation is: " << representation << "\n";
//     }
//     else{
//         //change into decimal
//         std::cout << "Enter binary number: ";
//         std::cin >> number;

//         //process
//         representation = BinToDec(number);

//         //output
//         std::cout << "The decimal representation is: " << representation << "\n";
//     }



//     return 0;
// }

//But we will use bitset
#include <bitset>


int main(){

    bool IsDecimal = true;
    int number1 = 0;
    std::string number2 = "00000000";
    


        //01-change into binary
        std::cout << "Enter decimal number: ";
        std::cin >> number1;

        //process
        std::bitset<8> binary(number1);

        //output
        std::cout << "The binary representation is: " << binary << "\n";
    

        //02-change into decimal
        std::cout << "Enter binary number: ";
        std::cin >> number2;

        //process
        std::bitset<8> binary2(number2);
        unsigned long decimal = binary2.to_ulong();

        //output
        std::cout << "The decimal representation is: " << decimal << "\n";
    



    return 0;
}
