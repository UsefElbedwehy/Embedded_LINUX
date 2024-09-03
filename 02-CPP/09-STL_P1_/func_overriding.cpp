//author: Usef Elbedwehy
//date: Tue 03 Sep 2024
//@session: 08
//@topic: OOP
//@brief: Inheritance
#include <iostream>


class Shape{
    private:
        int Shapex;
    public:
    Shape(){
        std::cout << "Constructor shape." << std::endl;
    }
    ~Shape(){
        std::cout << "Destructor Shape." << std::endl;
    }
    virtual void draw() {
        std::cout << "draw Shape." << std::endl;
    }
};
class Square: virtual public Shape{
    private:
        int Squarex;
    public:
    Square(): Shape(){
        std::cout << "Constructor Square." << std::endl;
    }
    ~Square(){
        std::cout << "Destructor Square." << std::endl;
    }
    void draw() override {
        std::cout << "draw Square." << std::endl;
    }
};
class Rect: virtual public Shape{
    private:
        int Rectx;
    public:
    Rect(): Shape(){
        std::cout << "Constructor Rect." << std::endl;
    }
    ~Rect(){
        std::cout << "Destructor Rect." << std::endl;
    }
    void draw() override {
        std::cout << "draw Rect." << std::endl;
    }
};
int main(){
    // Shape S1;
    // S1.draw();

    // Rect R1;
    // R1.draw();

    // Square S2;
    // S2.draw();

    Shape* shape1 = new Square();
    Shape* shape2 = new Rect();

    shape1->draw();
    shape2->draw();

    delete shape1;
    delete shape2;

    return 0;
}