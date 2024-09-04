//author: Usef Elbedwehy
//date: Wed 04 Sep 2024
//@session: 08
//@topic: OOP
//@brief: inheritance
#include <iostream>
#include <string>

int main(){

    // copy constructor (of temporary)
    std::string my_name = "Usef Elbedwehy";
    // paramereized constructor
    std::string his_name("Amr Ahmed");
    // constructor with a char and a repitition count
    std::string her_name(5,'a');
    // c style constructor
    const char* c_name = "c_language!";
    std::string embedded_system_lang(c_name);

    std::cout << embedded_system_lang << std::endl;
    std::cout << his_name << std::endl;
    std::cout << her_name << std::endl;

    //move constructor 
    std::string str5(std::move(her_name));

    std::cout << str5 << std::endl;

    //copy constructor 
    std::string herrr_name(str5);

    std::cout << herrr_name << std::endl;

    my_name.at(4) = 'X';
    std::cout << my_name << std::endl;
    std::cout << (my_name[4] = 'x') << std::endl;

    my_name.front() = 'z';
    my_name.back() = 'c';

    std::cout << my_name << std::endl;
    std::cout << *my_name.data() << std::endl;
    std::cout << *my_name.begin() << std::endl;
    std::cout << *(my_name.end()-1) << std::endl;
    std::cout << *my_name.cbegin() << std::endl;
    std::cout << *(my_name.cend()-1) << std::endl;

    if(my_name.empty()){
        std::cout << "Empty" << std::endl;
    }else{
        std::cout << "Not empty" << std::endl;
    }

    my_name.clear(); 
    
    if(my_name.empty()){
        std::cout << "Empty" << std::endl;
    }else{
        std::cout << "Not empty" << std::endl;
    }

    my_name = "Elephant is Animal!";

    std::cout << my_name.size() << std::endl;
    std::cout << my_name.length() << std::endl;
    std::cout << my_name.capacity() << std::endl;
    std::cout << my_name.max_size() << std::endl;

    my_name.reserve(20);

    std::cout << my_name.size() << std::endl;
    std::cout << my_name.length() << std::endl;
    std::cout << my_name.capacity() << std::endl;
    std::cout << my_name.max_size() << std::endl;


    return 0;
}
