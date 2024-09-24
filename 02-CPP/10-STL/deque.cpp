#include <iostream>
#include <deque>
#include <vector>
#include "deque.h"
int main(int argc, char const *argv[])
{
    std::deque<int> d{0,0,0};
    //      ------------
    //deque | 0 | 0 | 0 |
    //      ------------
    d.push_back(1);
    //      ---------------
    //deque | 0 | 0 | 0 | 1 |
    //      ---------------
    d.push_front(2);
    //      ---------------------
    //deque | 2 | 0 | 0 | 0 | 1 |
    //      ---------------------

    printD(d);

    std::vector<int> v{3,4,5,6};

    d.insert(d.begin(),v.begin(),v.end());

    printD(d);

    d.pop_front();

    printD(d);

    d.erase(d.begin()+2 ,d.begin()+5);

    printD(d);

    return 0;
}

void printD(std::deque<int> &d)
{
    for (auto num : d)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
