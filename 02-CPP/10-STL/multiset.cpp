#include <iostream>
#include <set>
#include "multiset.h"

int main(int argc, char const *argv[])
{
    std::multiset<int> numbers{1,2,3,3,3,4,5,6};

    printMultiSet(numbers);

    numbers.insert(4);
    printMultiSet(numbers);

    return 0;
}

void printMultiSet(std::multiset<int> &numbers)
{
    for (int i : numbers)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
