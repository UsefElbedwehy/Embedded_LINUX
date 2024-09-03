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




<h1>dynamic_cast in C++</h1>
    <p><code>dynamic_cast</code> is a C++ operator used for safely converting pointers or references between related classes, particularly within an inheritance hierarchy. It is primarily used in the context of polymorphism, where you may want to cast a base class pointer or reference to a derived class type.</p>
    
<h2>Key Features of <code>dynamic_cast</code></h2>
    <ul>
        <li><strong>Type Safety</strong>: <code>dynamic_cast</code> checks at runtime whether the conversion is valid (i.e., whether the object is actually of the target type or derived from it).</li>
        <li><strong>Polymorphism Requirement</strong>: It only works with polymorphic classes (i.e., classes that have at least one virtual function).</li>
        <li><strong>Runtime Check</strong>: If the cast is not valid, <code>dynamic_cast</code> returns <code>nullptr</code> when used with pointers or throws a <code>std::bad_cast</code> exception when used with references.</li>
    </ul>

<h2>Syntax</h2>
    <pre><code>dynamic_cast&lt;target_type&gt;(expression);</code></pre>

<h2>Use Cases</h2>
    <ul>
        <li><strong>Downcasting</strong>: Converting a pointer or reference to a base class type to a pointer or reference to a derived class type.</li>
        <li><strong>Cross-casting</strong>: Converting pointers or references between sibling classes in an inheritance hierarchy.</li>
    </ul>

<h2>Example: Downcasting with <code>dynamic_cast</code></h2>
    <pre><code>
#include &lt;iostream&gt;
#include &lt;typeinfo&gt;

class Base {
public:
    virtual void show() {
        std::cout &lt;&lt; "Base class" &lt;&lt; std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout &lt;&lt; "Derived class" &lt;&lt; std::endl;
    }
};

int main() {
    Base* basePtr = new Derived;  // Upcasting (implicit conversion)

    // Downcasting with dynamic_cast
    Derived* derivedPtr = dynamic_cast&lt;Derived*&gt;(basePtr);
    if (derivedPtr) {
        derivedPtr-&gt;show();  // Safe to call, because dynamic_cast was successful
    } else {
        std::cout &lt;&lt; "Downcast failed" &lt;&lt; std::endl;
    }

    delete basePtr;
    return 0;
}
    </code></pre>

<h2>Explanation</h2>
    <ul>
        <li><strong>Upcasting</strong>: The pointer <code>basePtr</code> of type <code>Base*</code> is assigned an object of type <code>Derived</code>. This is implicit and always safe.</li>
        <li><strong>Downcasting</strong>: The pointer <code>basePtr</code> is then cast back to <code>Derived*</code> using <code>dynamic_cast</code>. If the object that <code>basePtr</code> points to is indeed a <code>Derived</code> object, the cast succeeds, and <code>derivedPtr</code> is valid.</li>
        <li><strong>Safety</strong>: If the cast is not valid (e.g., <code>basePtr</code> was actually pointing to a <code>Base</code> object), <code>dynamic_cast</code> returns <code>nullptr</code>, preventing undefined behavior from occurring when trying to access members of <code>Derived</code>.</li>
    </ul>

<h2>Example: Cross-casting with <code>dynamic_cast</code></h2>
    <pre><code>
class Base {
    virtual void foo() {}  // Must be polymorphic
};

class Derived1 : public Base { };
class Derived2 : public Base { };

int main() {
    Base* base = new Derived1;

    // Trying to cross-cast
    Derived2* derived2 = dynamic_cast&lt;Derived2*&gt;(base);

    if (derived2 == nullptr) {
        std::cout &lt;&lt; "Cross-cast failed" &lt;&lt; std::endl;
    } else {
        std::cout &lt;&lt; "Cross-cast succeeded" &lt;&lt; std::endl;
    }

    delete base;
    return 0;
}
    </code></pre>

<h2>Explanation</h2>
    <p>Here, we attempt to cast a <code>Base*</code> pointer that actually points to a <code>Derived1</code> object into a <code>Derived2*</code> pointer. Since <code>Derived1</code> and <code>Derived2</code> are unrelated, the cast fails, and <code>derived2</code> is set to <code>nullptr</code>.</p>

<h2>When to Use <code>dynamic_cast</code></h2>
    <ul>
        <li><strong>Safe Downcasting</strong>: When you're unsure if a base class pointer/reference actually points to an object of a derived class.</li>
        <li><strong>Polymorphic Types</strong>: When working with a class hierarchy involving polymorphism (virtual functions).</li>
    </ul>

<h2>When Not to Use <code>dynamic_cast</code></h2>
    <ul>
        <li><strong>Non-polymorphic Types</strong>: If your classes do not have virtual functions, <code>dynamic_cast</code> is unnecessary and won’t work.</li>
        <li><strong>Performance</strong>: <code>dynamic_cast</code> incurs a runtime cost, so avoid using it in performance-critical sections of code when possible.</li>
    </ul>

<p>In summary, <code>dynamic_cast</code> is a powerful tool for type-safe casting in C++, particularly in complex class hierarchies where runtime type checking is required.</p>


</body>
</html>
