//  Interface and Multiple Inheritance:
    // -Create an interface class Drawable with a pure virtual function draw().
    // -Derive classes like Circle, Rectangle, and Triangle from Shape and implement the Drawable
    // interface.
    // -Create objects of these derived classes and call the draw() function through a pointer to the
    // Drawable interface
#include <iostream>
// SOLID PRINCIPLE CHECK:
// // 1- S: single responsibility principle: (only one reason to modify the class)
// // 2- O: open/closed principle: open for extension ,closed for modification
// // 3- L: Liskov substitution: Objects of a derived class should be able to replace 
//                                              objects of the base class without altering the correctness of the program.
// // 4- I: interface segregation principle: Clients should not be forced to depend on interfaces they do not use.
// // 5- D: Dependency inversion: High-level modules should not depend on low-level modules.
//                                              Both should depend on abstractions (e.g., interfaces).


class Drawable {
    public:
        virtual void draw() const = 0;
        virtual ~Drawable(){};
};

class Rectangle : public Drawable
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Rectangle" << std::endl;
    }
};

class Circle : public Drawable
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Circle" << std::endl;
    }
};
class Triangle : public Drawable
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Triangle" << std::endl;
    }
};

class Shape
{
private:
    Drawable* Dshape;
public:
    Shape(Drawable* dshape):Dshape(dshape){

    }
    void draw(){
        Dshape->draw();
    }
    ~Shape(){

    }
};





int main(int argc, char const *argv[])
{
    Shape Cshape(new Circle);
    Cshape.draw();    




    return 0;
}
