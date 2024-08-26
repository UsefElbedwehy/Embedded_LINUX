#include <iostream>

class Complex{

private:
    int real;
    float img;


public:
    friend std::ostream &operator<<(std::ostream& os,Complex& C);
    friend int operator+(int f,Complex& c);
    friend float operator+(float f,Complex& c);
    Complex():real(0),img(0.0f) {

    }
    Complex(int r,float i):real(r),img(i) {

    }
    ~Complex(){

    }
    int operator+(int copy_real){
        return real + copy_real ;
    }
    float operator+(float copy_img){
        return img + copy_img ;
    }
    Complex operator+(Complex &c){
        Complex Bridge;
        Bridge.real = this->real + c.real;
        Bridge.img  = this->img  + c.img;
        return Bridge;
    }
    Complex operator=(int n){
        this->real = n;
        return *this;
    }
    Complex operator=(float i){
        this->img = i;
        return *this;
    }
    Complex operator=(Complex c){
        this->real = c.real;
        this->img  = c.img;
        return *this;
    }
    void operator()(void){
        std::cout << "Real: " << real << std::endl;
        std::cout << "Img: " << img << "i" << std::endl;
    }
 


};
float operator+(float f,Complex& c){
    return f+c.img ;
}
int operator+(int f,Complex& c){
    return f+c.real ;
}
   //printing
    std::ostream &operator<<(std::ostream& os,Complex& C){
        std::cout << "complex: " << C.real << " + " << C.img << "i" ;
        return os;
    }
int main(){

    int real_nmber = 0;
    float img_number = 0.0f;

    Complex C1(3,4.7f);
    Complex C2(8,1.8f);
    Complex C3{};

    real_nmber = C1 + 7;              // real_number = C1.operator+(7)                                  (return int)
    img_number = C1 + 4.5f;           // img_number  = C1.operator+(4.5f)                               (return float)
    //Complex: 10 + 9.2i
    std::cout << "complex: " << real_nmber 
        <<" + "<< img_number << "i" <<std::endl;

    real_nmber = 22   + C2;           // real_nmber = operator+(22,C1)                                  (return int)
    img_number = 4.4f + C2;           // img_number = operator+(4.4f,C1)                                (return float)
    //Complex: 30 + 6.2i
    std::cout << "complex: " << real_nmber 
        <<" + "<< img_number << "i" <<std::endl;

    C3 = C1 + 7;                      //C3.operator=(C1.operator(7))     = C3.operator=(int)            (return Complex)
    //Complex: 10 + 0i
    std::cout << C3 <<std::endl;

    C3 = C1 + 4.5f;                   //C3.operator=(C1.operator(4.5f))  = C3.operator=(float)          (return Complex)
    //Complex: 10 + 9.2i
    std::cout << C3 <<std::endl;

    C3 = C1 + C2;                     //C3.operator=(C1.operator(C2))    = C3.operator=(Complex)        (return Complex)
    //Complex: 11 + 6.5i
    std::cout << C3 <<std::endl;

    C1();                               // C1.operator()(void)
    C2();                               // C2.operator()(void)
    C3();                               // C3.operator()(void)
    Complex(); // its hust temp nothing will happen

    return 0;
}