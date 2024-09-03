<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Polymorphism in OOP</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 20px;
        }
        code {
            background-color: #f4f4f4;
            padding: 2px 5px;
            border-radius: 3px;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 5px;
        }
        h2 {
            color: #333;
        }
    </style>
</head>
<body>
    <h1>Polymorphism in Object-Oriented Programming (OOP)</h1>
    <p>Polymorphism is a fundamental concept in Object-Oriented Programming (OOP) that allows objects of different types to be treated as objects of a common base type. It's one of the key principles that make OOP powerful and flexible.</p>

<h2>Types of Polymorphism</h2>
    <h3>1. Compile-Time Polymorphism (Static Polymorphism)</h3>
<p>This is achieved through function overloading and operator overloading. The method to be invoked is determined at compile time.</p>
    
<h4>Example: Function Overloading</h4>
<pre><code>class Print {
public:
    void display(int i) {
        std::cout << "Integer: " << i << std::endl;
    }
    void display(double f) {
        std::cout << "Float: " << f << std::endl;
    }
    void display(const std::string& str) {
        std::cout << "String: " << str << std::endl;
    }
};

int main() {
    Print p;
    p.display(5);
    p.display(3.14);
    p.display("Hello, World!");
    return 0;
}</code></pre>

    <p><strong>Output:</strong></p>
    <pre><code>Integer: 5
Float: 3.14
String: Hello, World!</code></pre>
    <p>In this example, the <code>display</code> function is overloaded to handle different types of arguments.</p>

<h3>2. Run-Time Polymorphism (Dynamic Polymorphism)</h3>
    <p>This is achieved through inheritance and virtual functions. The method to be invoked is determined at runtime based on the object type.</p>

<h4>Example: Virtual Functions</h4>
    <pre><code>class Animal {
public:
    virtual void sound() {
        std::cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Cat meows" << std::endl;
    }
};

int main() {
    Animal* animal;
    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();  // Outputs: Dog barks

    animal = &cat;
    animal->sound();  // Outputs: Cat meows

    return 0;
}</code></pre>
    <p>In this example, the <code>sound</code> function is virtual in the <code>Animal</code> class. Depending on the object type (<code>Dog</code> or <code>Cat</code>), the appropriate overridden function is called at runtime.</p>

<h2>Why Polymorphism is Important</h2>
<ul>
        <li><strong>Code Reusability:</strong> You can write generic code that works with different types of objects.</li>
        <li><strong>Flexibility:</strong> New classes can be added with minimal changes to the existing codebase.</li>
        <li><strong>Maintainability:</strong> Polymorphism leads to cleaner and more maintainable code by adhering to the principle of "programming to an interface, not an implementation."</li>
    </ul>

<h2>Real-World Analogy</h2>
    <p>Consider a remote control that can operate multiple devices (TV, DVD player, AC). Although the remote control is a single interface, the action it performs depends on the device it's controlling, similar to how polymorphism allows different objects to respond to the same function call in different ways.</p>

<p>Polymorphism is a key feature that makes OOP powerful, allowing for dynamic and flexible code that can adapt to different types and behaviors at both compile-time and runtime.</p>
</body>
</html>
