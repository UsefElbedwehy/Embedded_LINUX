#include <iostream>
#include <utility>

template<typename T>
class DataTemp
{
private:
    /* data */
public:
    
    void swap(T& a,T& b){
        auto temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

};

// [1]
// template<typename T>
// void swap(T& a,T& b){
//     auto temp = std::move(a);
//     a = std::move(b);
//     b = std::move(temp);
// }


int main(int argc, char const *argv[])
{
    // [1]
    // std::string a1{"Hello"},b1{"world"};
    // std::cout << "before swap: " << std::endl;
    // std::cout << "          a1: " << a1 << " & b1: " << b1 << std::endl;
    // swap(a1,b1);
    // std::cout << "after swap: " << std::endl;
    // std::cout << "          a1: " << a1 << " & b1: " << b1 << std::endl;
    
    DataTemp<double>D;
    double aa=4.4;
    double bb=3.3;
    std::cout << "[double]" << std::endl;
    std::cout << "before swap: v1= " << aa << " | V2= "<< bb << std::endl;
    D.swap(aa,bb);
    std::cout << "after swap: v1= " << aa << " | V2= "<< bb << std::endl;

    DataTemp<int>DD;
    int aaa=4;
    int bbb=3;
    std::cout << "[int]" << std::endl;
    std::cout << "before swap: v1= " << aaa << " | V2= "<< bbb << std::endl;
    DD.swap(aaa,bbb);
    std::cout << "after swap: v1= " << aaa << " | V2= "<< bbb << std::endl;

    DataTemp<float>DDD;
    float aaaa=4.444f;
    float bbbb=3.333f;
    std::cout << "[float]" << std::endl;
    std::cout << "before swap: v1= " << aaaa << " | V2= "<< bbbb << std::endl;
    DDD.swap(aaaa,bbbb);
    std::cout << "after swap: v1= " << aaaa << " | V2= "<< bbbb << std::endl;

    return 0;
}
