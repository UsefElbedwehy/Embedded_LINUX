#include <iostream>
#include <vector>
#include <set>
#include "set.h"

int main(int argc, char const *argv[])
{
    std::set<int> numbers{8,2,3,6,5,7,98,77};

    //print set
    printSet(numbers);
    // --------- insert -----------------
    // insert number which is found in the set, to show that the set is unique and ordered
    numbers.insert(3);
    // insert number
    numbers.insert(88);
    printSet(numbers);
    // insert smaller one to show that the insertion does not affect the order
    numbers.insert(87);
    printSet(numbers);
    // --------- erase -----------------
    //erase a number by random access , earse could not be from head or tail only
    numbers.erase(3);
    printSet(numbers);

    // insert a number 
    numbers.insert(3);
    printSet(numbers);

    // --------- find -----------------
    if(numbers.find(44) != numbers.end()){
        std::cout << "Number "<< 44 << " is found...:)" << std::endl;
    }
    else{
        std::cout << "Number "<< 44 << " is not found...:(" << std::endl;
    }
    if(numbers.find(3) != numbers.end()){
        std::cout << "Number "<< 3 << " is found...:)" << std::endl;
    }
    else{
        std::cout << "Number "<< 3 <<  " is not found...:(" << std::endl;
    }
    printSet(numbers);
    int nm_lb = -1;
    auto it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<")"<<": "<< *it << std::endl;
    nm_lb = 0;
    it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<")" <<": "<< *it << std::endl;
    nm_lb = 1;
    it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<")" <<": "<< *it << std::endl;
    nm_lb = 7;
    it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<"): "<< *it << std::endl;
    nm_lb = 87;
    it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<"): "<< *it << std::endl;
    nm_lb = 88;
    it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<"): "<< *it << std::endl;
    nm_lb = 99;
    it = numbers.lower_bound(nm_lb);
    std::cout << "Lower bound("<< nm_lb <<"): "<< *it << std::endl;

    // no operator[]
    //std::cout << numbers[2] << std::endl;

    if (numbers.find(88) != numbers.end())
    {
        numbers.erase(88);
        std::cout << "Erase is done successfully!" << std::endl;
        printSet(numbers);
    }else{
        std::cout << "not found...no erase" << std::endl;
    }
    

    return 0;
}

void printSet(std::set<int> &numbers)
{
    std::cout << "set: " ;
    for (int i : numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << std::string(30,'-') << std::endl;
}
