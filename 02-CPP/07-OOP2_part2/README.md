<!DOCTYPE html>
<html>
<body>
<p>create file: main1.cpp</p>
<pre>
touch main1.cpp && code main1.cpp
</pre>
<h2>
Default Copy Constructor
</h2>
<p>If you don’t define a copy constructor, the compiler provides a default copy constructor that performs a shallow copy. This means that it copies member variables bit by bit, which can be problematic if your class manages dynamic memory or other resources like file handles.</p>
<h2>
Copy constructor (Shallow copy vs Deep copy)
</h2>
<ul>
<li><p>
<strong>Shallow Copy:</strong> The default copy constructor provided by the compiler copies the object by copying the address of the memory where the data is stored. This can lead to issues like double-freeing memory (when both objects point to the same memory and both destructors try to free it).
</p></li>
<li><p>
<strong>Deep Copy:</strong> A user-defined copy constructor can be used to allocate separate memory for the new object, copying the actual contents of the original object rather than just the memory address.
</p></li>
</ul>
<p><strong>Resource Management:</strong> When your class manages resources (like dynamic memory, file handles, etc.), a copy constructor ensures proper management of those resources, avoiding memory leaks and other issues.</p>
<h3>When to use copy constructor:</h3>
<ul>
<li>Initialized from another object of the same class.</li>
<li>Passed by value to a function.</li>
<li>Returned from a function by value.</li>
<li>Explicitly copied using assignment.</li>
</ul>

<h3>The overall syntex of deep copy</h3>
<pre>
<code>
        //copy constructor (Deep copy)
        String(const String& copy): size(copy.size), str(new char(copy.size + 1)){
            std::cout << "Copy constructor is called." << std::endl; 
            strcpy(str , copy.str);
        }
</code>
</pre>
<h3>Operator = copy assignment overload</h3>
<pre>
<code>
        String& operator=(const String& Bridge){
            if(&Bridge == this){
                return *this;
            }
            delete[] str;
            this->size = Bridge.size;
            this->str = new char(size + 1);
            strcpy(this->str,Bridge.str);  
            return *this;
        }
</code>
</pre>
<h3>When is the Copy Constructor Called?</h3>
<ul>
<li>
When an object is initialized at the time of creation:
<pre>
ClassName obj1 = obj2;  // Copy constructor is called
</pre>
</li>
<li>
When an object is passed by value to a function:
<pre>
void func(ClassName obj);  // Copy constructor is called when the object is passed by value
</pre></li>
<li>
When an object is returned from a function by value:
<pre>
ClassName func() {
    ClassName obj;
    return obj;  // Copy constructor is called
}
</pre></li>
</ul>
<h2>Compile Your Program with Debug Information</h2>
<ol>
<li>
To get the most accurate results, compile your program with debugging information. Use the -g flag with g++ or gcc:
<pre>g++ -g your_program.cpp -o your_program</pre>
</li>
<li>
Run Valgrind , Basic Memory Check: (To check for memory leaks and invalid memory usage:)
<pre>valgrind --leak-check=full ./your_program</pre>
</li>
</ol>
<hr/>
<p>create file: main2.cpp</p>
<pre>
touch main2.cpp && code main2.cpp
</pre>
<h2>Value Category:</h2>
<p>In C++, value categories describe how an expression behaves regarding its value, lifespan, and ability to be assigned to or moved from. Understanding value categories is essential when working with expressions, function returns, and variable assignments.</p>
<h2>Main Value Categories:</h2>

<h3>1. Prvalue (Pure rvalue)</h3>
    <p>Represents a temporary value or literal that does not have a specific memory address and cannot be assigned to.</p>
    <p>Typically results from literals, temporary objects, or the result of a function that returns a non-reference type.</p>
    <p><strong>Example:</strong></p>
    <pre><code>int x = 5 + 10;  // 5 + 10 is a prvalue
int y = 42;      // 42 is a prvalue</code></pre>

<h3>2. Lvalue</h3>
    <p>Represents an object or function with a persistent address in memory that can be assigned to.</p>
    <p>Lvalues have a name or are referable by an address.</p>
    <p><strong>Example:</strong></p>
    <pre><code>int a = 10;    // a is an lvalue
a = 20;        // a can be assigned a new value</code></pre>

<h3>3. Xvalue (Expiring value)</h3>
    <p>Represents an object that is near the end of its lifetime, such as an rvalue reference.</p>
    <p>Typically occurs in contexts involving move semantics.</p>
    <p><strong>Example:</strong></p>
    <pre><code>int&& r = 5;        // 5 is a prvalue, r is an xvalue
int&& func();       // result of func() is an xvalue
std::move(a);       // std::move(a) is an xvalue</code></pre>

<h3>4. Glvalue (Generalized lvalue)</h3>
    <p>A union of lvalues and xvalues, representing expressions that have an identifiable memory location.</p>
    <p><strong>Example:</strong></p>
    <pre><code>int b = 20;     // b is an lvalue, hence a glvalue
int&& r = std::move(b);  // std::move(b) is an xvalue, hence a glvalue</code></pre>

<h3>5. Rvalue (Right value)</h3>
    <p>A union of prvalues and xvalues, representing expressions that can be moved from or used in temporary contexts.</p>
    <p><strong>Example:</strong></p>
    <pre><code>int&& r = 5;   // 5 is an rvalue (specifically a prvalue)
std::move(b);  // std::move(b) is an rvalue (specifically an xvalue)</code></pre>

<h2>Key Differences and Usage:</h2>

<ul>
        <li><strong>Lvalue:</strong> Represents an object with a distinct memory address and a long lifespan. It can be used on the left side of an assignment.</li>
        <li><strong>Rvalue:</strong> Typically a temporary, disposable value. Cannot be assigned to directly but can be moved (especially useful in move semantics).</li>
        <li><strong>Prvalue:</strong> Pure temporary value, often the result of expressions like arithmetic operations or object constructors.</li>
        <li><strong>Xvalue:</strong> Used in the context of move semantics to signify that the value is about to be moved or destroyed.</li>
    </ul>

<h2>Example in Code:</h2>

<pre><code>int x = 10;         // x is an lvalue
int y = x + 5;      // x + 5 is a prvalue
int&& r = x + 5;    // x + 5 is an rvalue, r is an xvalue

int z = std::move(x);  // std::move(x) is an xvalue, moved to z</code></pre>

<p>In this example:</p>
    <ul>
        <li><code>x</code> is an lvalue.</li>
        <li><code>x + 5</code> is a prvalue (temporary result).</li>
        <li><code>std::move(x)</code> produces an xvalue, which is used to move <code>x</code> to <code>z</code>.</li>
    </ul>
</body>
</html>