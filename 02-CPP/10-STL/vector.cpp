#include <iostream>
#include <vector>
#include <string.h>
int main(int argc, char const *argv[])
{
    std::vector<char> vnumber{'1','2','4','7','9'};
    std::vector<int>  ivnumber(4,2);
    std::vector<int>  iivnumber(4,6);
    for(auto num : vnumber){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    vnumber.front() = 'a';
    vnumber[1] = 'b';
    vnumber.at(2) = 'c';
    vnumber.at(3) = 'd';
    vnumber.back()='e';

    for(auto num : vnumber){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;
    
    vnumber.reserve(32);


    vnumber.push_back('f');
    std::cout << "size    : " << vnumber.size() << std::endl;
    std::cout << "capacity: " << vnumber.capacity() << std::endl;

    std::cout << std::string(30,'-') << std::endl ;
    
    for(auto num : vnumber){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    for(auto inum : ivnumber){
        std::cout << inum << " ";
    }
    std::cout << std::endl;
    std::cout << std::string(30,'-') << std::endl ;
    
    ivnumber.assign(7,5);
    std::cout << "after ivnumber.assign(7,5):"<< std::endl;
    for(auto inum : ivnumber){
        std::cout << inum << " ";
    }
    std::cout << std::endl;
    std::cout << std::string(30,'-') << std::endl ;
    
    ivnumber = iivnumber;
    std::cout << "after ivnumber = iivnumber: "<< std::endl;
    std::cout << "iivnumber: ";
    for(auto num : iivnumber){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "ivnumber: ";
    for(auto inum : ivnumber){
        std::cout << inum << " ";
    }
    std::cout << std::endl;
    std::cout << std::string(30,'-') << std::endl ;
    
    ivnumber.assign(7,5);
    std::cout << "after ivnumber.assign(7,5):"<< std::endl;
    std::cout << "iivnumber: ";
    for(auto num : iivnumber){
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "ivnumber: ";
    for(auto inum : ivnumber){
        std::cout << inum << " ";
    }
    std::cout << std::endl;

    std::cout << std::string(30,'-') << std::endl ;
    auto e = ivnumber.rend();
    std::cout << "&e()[0] = "<< &e[0] << std::endl;
    std::cout << "&ivnumber[-1] = "<< &ivnumber[-1] << std::endl; 
    std::cout << "ivnumber[-1] = "<< ivnumber[-1] << std::endl; 
    std::cout << "*rend() = " << *e << std::endl;

    std::cout << std::string(15,'-') << "push_back vs emplace_back" << std::string(15,'-') << std::endl ;

    ivnumber.push_back(12);
    ivnumber.emplace_back(13);
    std::cout << "ivnumber: ";
    for(auto inum : ivnumber){
        std::cout << inum << " ";
    }
    std::cout << std::endl;
    int random_num = 14;
    ivnumber.push_back(random_num);
    ivnumber.emplace_back();
    std::cout << "ivnumber: ";
    for(auto inum : ivnumber){
        std::cout << inum << " ";
    }
    std::cout << std::endl;
    std::cout << std::string(30,'-') << std::endl ;
    

    std::cout << std::string(30,'-') << std::endl ;
    

    return 0;
}
