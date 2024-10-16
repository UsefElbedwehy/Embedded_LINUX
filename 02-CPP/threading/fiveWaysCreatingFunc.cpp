#include <iostream>
#include <thread>

//[1] function
void fun(int x){
    while (x-- > 0){
        std::cout << x << " " ;
    }
    std::cout << std::endl;
}
//[2] lambda
auto fun2 = [](int x){
    while (x-- > 0){
        std::cout << x << " " ;
    }
    std::cout << std::endl;};
//[3] functor
class func345
{
public:
    void operator()(int x) {
        while (x-- > 0){
        std::cout << x << " " ;
    }
    std::cout << std::endl;
    }
    //[4] non-static function
    void fun4(int x){
        while (x-- > 0){
        std::cout << x << " " ;
    }
    std::cout << std::endl;
    }
    //[5] static function
    static void fun5(int x){
        while (x-- > 0){
        std::cout << x << " " ;
    }
    std::cout << std::endl;
    }
    func345(/* args */);
    ~func345();
};

func345::func345(/* args */)
{
}

func345::~func345()
{
}


int main(int argc, char const *argv[])
{
    func345 f;
    std::thread t1(fun,10);
    std::thread t2(fun2,10);
    std::thread t3(func345(),10);
    std::thread t4(&func345::fun4,&f,10);
    std::thread t5(&func345::fun5,10);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}
