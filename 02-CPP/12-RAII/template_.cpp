#include <iostream>
//[1] basic template single argument type
template<typename T> 
T division(T x,T y){
    try
        {
    if(y != 0){
        return x/y;
    }else{
        //std::cout << "Cannot divide by zero." << std::endl;
            throw std::runtime_error("Division by zero.");
            
        return x;
    }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << "Caught Exception in function: " << e.what() << '\n';
            throw;
        }
        return 0;
}

//[2] basic template multi argument type
template<typename T,typename U> 
T division(T x,U y){
    if(y != 0){
        return x/y;
    }else{
        try
        {
            //std::cout << "Cannot divide by zero." << std::endl;
            throw std::runtime_error("Division by zero.");
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << e.what() << '\n';
            throw;
        }
        
    }
}

//[3] class template 
template<typename T>
class Container
{
private:
    T value;
public:
    Container(T val) : value(val){
        std::cout << std::string(30,'-') << std::endl;
        std::cout << "Conatiner created [constructor]." << std::endl;}
    void print(){
        std::cout << "Value: " << value << std::endl;
    }
    ~Container(){
    std::cout << "Conatiner destroyed [destructor]." << std::endl;
    std::cout << std::string(30,'-') << std::endl;
    }
};

//[4] class template with standalone function 
template<typename T> 
class Container2 {
    private:
        T value;
    public:
        Container2(T val) : value(val){
            std::cout << std::string(30,'-') << std::endl;
            std::cout << "Conatiner2 created [constructor]." << std::endl;}
        template<typename U>
        void add(U val){
            value +=val;
            std::cout << "add: " << val << std::endl;
        }
        void print(){
            std::cout << "Value: " << value << std::endl;
        }
        ~Container2(){
            std::cout << "Conatiner2 destroyed [destructor]." << std::endl;
            std::cout << std::string(30,'-') << std::endl;}
};

//[5] explicit specialization
template<> class Container<float>
{
private:
    float value;
public:
    Container(float val):value(val){
        std::cout << std::string(30,'-') << std::endl;
        std::cout << "Specialized constructor." << std::endl;
    }
    ~Container(){
        std::cout << "Specialized destructor." << std::endl;
        std::cout << std::string(30,'-') << std::endl;
    }

};

//[6] primary template and partial specialization
template<typename T, typename U> 
struct usr{ //primary template
    
    usr(T t,U u){
        std::cout << std::string(30,'-') << std::endl;
        std::cout << "[+]primary template" << std::endl;}
    ~usr(){
        std::cout << "[-]primary template" << std::endl;
        std::cout << std::string(30,'-') << std::endl;
    }
};
template<typename T> 
struct usr<T,T>{ //partial specialization
    usr(T t,T u){
        std::cout << std::string(30,'-') << std::endl;
        std::cout << "[+]partial specialization" << std::endl;}
    ~usr(){
        std::cout << "[-]partial specialization" << std::endl;
        std::cout << std::string(30,'-') << std::endl;
    }
};

//[7] default temlate arguments 
template<typename T,typename U = int>
class A
{
private:
    T t;
    U u;
public:
    A(T tt,U uu): t(tt) , u(uu){}
    ~A(){}
};

//[8] const template expression
    template <typename T,int size> 
    class MyArray
    {
    private:
        T data[size];
    public:
        MyArray(){
            for(int i=0;i<size;i++){
                data[i]=i;
            }
        };
        ~MyArray(){};
    };
    

    

int main(int argc, char const *argv[])
{
    std::cout << std::string(30,'-') << std::endl;
    //[1]
    auto div1 = division(22,2);
    std::cout << "div1= " << div1 << std::endl;

    std::cout << std::string(30,'-') << std::endl;
    //[2]
    auto div2 = division(22.2,1.2f);
    std::cout << "div2= " << div2 << std::endl;

    //[3]
    Container<int> C1(22);
    C1.print();

    //[4]
    Container2<int> C2(33);
    C2.print();
    C2.add(3.3);
    C2.print();
    C2.add(4);
    C2.print();

    //[5]
    Container<float> C3(3.3);
    
    //[6]
    usr<int ,float> U1(2,1.1f);
    usr<float,float> U2(2.3f,3.2f);

    //[7]
    A<int> a1(5,5);

    //[8]
    MyArray<int ,5> MA1;
    

    return 0;
}
