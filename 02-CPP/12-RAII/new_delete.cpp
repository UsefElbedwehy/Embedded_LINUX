#include <algorithm>
#include <iostream>

// steps to check the memory leakage:
// 1- compile the program: g++ -g new_delete.cpp && ./a.out 
// run the program using valgring : valgrind --leak-check=full ./a.out 

int main(int argc, char const *argv[])
{
    int *p = new int{5};
    *p = 6;
    std::cout << "after creation: *p: "<< *p << std::endl;
    delete p;
    std::cout << "after deletion: *p: "<< *p << std::endl;
    *p = 6;
    std::cout << "after deletion and modification: *p: "<< *p << std::endl;


    int *pp = new int[3]{1,2,3};
    std::for_each(&pp[0],&pp[3],[](int i){std::cout << i << " ";});
    std::cout << std::endl;
    delete [] pp;
    std::for_each(&pp[0],&pp[3],[](int i){std::cout << i << " ";});
    std::cout << std::endl;


    //to solve it, you should assign pointer to null_ptr
    p  = nullptr;
    pp = nullptr;

    *p = 6;         // Segmentation fault (core dumped)
    pp[0] = 6;      // Segmentation fault (core dumped)



    return 0;
}
