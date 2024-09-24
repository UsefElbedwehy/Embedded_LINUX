//  Interface and Multiple Inheritance:
    // -Create an interface class Drawable with a pure virtual function draw().
    // -Derive classes like Circle, Rectangle, and Triangle from Shape and implement the Drawable
    // interface.
    // -Create objects of these derived classes and call the draw() function through a pointer to the
    // Drawable interface
#include <iostream>


// step1: reate an interface class Drawable with a pure virtual function draw().
class Drawable {
    public:
        virtual void draw() const = 0;
        virtual ~Drawable(){};
};
// step2: Derive classes like Circle, Rectangle, and Triangle from Shape and implement the Drawable interface.
class Shape : public Drawable
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Shape" << std::endl;
    }
};

class Rectangle : public Shape
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Rectangle" << std::endl;
    }
};

class Circle : public Shape
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Circle" << std::endl;
    }
};
class Triangle : public Shape
{
private:
    /* data */
public:
    void draw() const override{
        std::cout << "Triangle" << std::endl;
    }
};




int main(int argc, char const *argv[])
{
    
    Drawable* cshape = new Circle;
    Drawable* rshape = new Rectangle;
    Drawable* tshape = new Triangle;

    cshape->draw();
    rshape->draw();
    tshape->draw();

    return 0;
}



