#include <iostream>

template<typename T>
void print(T arg){
    //std::cout << "-----------------------" << std::endl;
    std::cout << arg << " " << std::endl;
    //std::cout << "-----------------------" << std::endl;
}
 //variadic template
 template<typename T,typename ...Args>
void print(T argt, Args ...args){
    //std::cout << "++++++++++++++++++++++++" << std::endl;
    std::cout << argt << " ";
    //std::cout << "++++++++++++++++++++++++"<< std::endl;
    print(args...);
    //std::cout << "++++++++++++++++++++++++" << std::endl;
}

int main(int argc, char const *argv[])
{
    print(12,12.2,"Usef",'a');
    //it is like:
    //[1]: print(12,12.2,"Usef",'a');
    //          std::cout << 12 << " ";
    //[2]: print(12.2,"Usef",'a');
    //          std::cout << 12.2 << " ";
    //[3]: print("Usef",'a');
    //          std::cout << "Usef" << " ";
    //[2]: print('a');
    //          print('a); 
    //          which is: std::cout << 'a' << " " << std::endl;
    

    return 0;
}
