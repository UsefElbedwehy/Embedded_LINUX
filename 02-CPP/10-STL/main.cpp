#include <iostream>
/////////////////////////////////////////////////////////////////
// getline
//use getline to get input from user
/////////////////////////////////////////////////////////////////
// int main()
// {
//     std::string my_full_name;
//     std::cout << "Enter ur name: " ;
//     getline(std::cin ,my_full_name ,'\t');
//     std::cout << "Your name is: " << my_full_name << std::endl;
    
//     return 0;
// }
/////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////
// STL
// array
/////////////////////////////////////////////////////////////////
#include <array>

int main()
{
    std::array<int , 5> numbers = {11,12,13,43,54};
    const int* ptr1 = numbers.cbegin();
    int* ptr2 = numbers.begin();
    std::cout << "Elment"<< 2 <<" : " << numbers[2] << std::endl;
    numbers.at(2) = 22; 
    std::cout << "Elment"<< 2 <<" : " << numbers[2] << std::endl;
    numbers.front() = 90;
    std::cout << "Elment"<< 0 <<" : " << numbers[0] << std::endl;
    numbers.back() = 80;
    std::cout << "Elment"<< 4 <<" : " << numbers.at(numbers.size()-1) << std::endl;
    std::cout << "Elment"<< 0 <<" : " << *numbers.data() << std::endl;

    std::cout << "Elment"<< 0 <<" : " << *ptr1 << std::endl;
    std::cout << "Elment"<< 0 <<" : " << *ptr2 << std::endl;    


    std::cout << "Element"<< numbers.size() - 1 <<" : " << &numbers[4] << std::endl; 
    std::cout << "Invalid Element"<< numbers.size()  <<" : " << &numbers[5] << std::endl; 
    std::cout << "Invalid Element"<< numbers.size()  <<" : " << numbers.end() << std::endl; 

    std::cout << "Element"<< numbers.size() - 1 <<" : " << numbers[4] << std::endl;  
    std::cout << "Invalid Element"<< numbers.size()  <<" : " << *numbers.rbegin() << std::endl;

    std::cout << "rend Element"<< " : " << *numbers.rend() << std::endl;
    std::cout << "Invalid Element"  <<" : " << numbers[-1] << std::endl;

    std::cout << "Is empty? " << numbers.empty() << std::endl;
    std::cout << "Max size: " << numbers.max_size() << std::endl;
    
    numbers.fill(0);

    for(int i : numbers ){
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    std::array<int ,6> n1{10,20,30,40,50,60};
    std::array<int ,6> n2{11,22,33,44,55,66};
    for(int i : n1 ){
        std::cout << i << " " ;
    }
    std::cout << std::endl;
    for(int i : n2 ){
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    n1.swap(n2);
    for(int i : n1 ){
        std::cout << i << " " ;
    }
    std::cout << std::endl;
    for(int i : n2 ){
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    return 0;
}
/////////////////////////////////////////////////////////////////