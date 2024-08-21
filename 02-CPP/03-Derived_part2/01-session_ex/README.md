<!DOCTYPE html>
<html lang="en">
<body>
    <h2>const vs constexpr in C++</h2>
    <h3>1. <code>const</code> Keyword</h3>
    <p><strong>Purpose</strong>: <code>const</code> is used to define a variable whose value cannot be modified after it has been initialized. The value of a <code>const</code> variable is determined at runtime or compile-time, depending on how it is initialized.</p>
    <pre><code>const int x = 10;  // x is a constant integer</code></pre>
    <p><strong>Characteristics</strong>:</p>
    <ul>
        <li>The value of a <code>const</code> variable can be determined at runtime or compile-time.</li>
        <li><code>const</code> variables can be used in both runtime and compile-time contexts, but they are not guaranteed to be evaluated at compile-time.</li>
        <li><code>const</code> can also be used with pointers and references to prevent modification of the pointed-to data.</li>
    </ul>
    <pre><code>const int* ptr = &x;  // ptr points to a constant integer (cannot modify the integer through ptr)</code></pre>
    <h3>2. <code>constexpr</code> Keyword</h3>
    <p><strong>Purpose</strong>: <code>constexpr</code> is used to define an expression that is guaranteed to be evaluated at compile-time. This allows for optimizations and ensures that the value is known during compilation.</p>
    <pre><code>constexpr int x = 10;  // x is a constant integer evaluated at compile-time</code></pre>
    <p><strong>Characteristics</strong>:</p>
    <ul>
        <li>The value of a <code>constexpr</code> variable must be determined at compile-time.</li>
        <li><code>constexpr</code> is often used for defining compile-time constants, functions, and expressions.</li>
        <li>A <code>constexpr</code> function can be evaluated at compile-time if its arguments are compile-time constants, or at runtime if the arguments are runtime values.</li>
    </ul>
    <pre><code>constexpr int square(int n) {
    return n * n;
}
constexpr int x = square(4);  // x is evaluated at compile-time
</code></pre>
    <h3>3. Key Differences</h3>
    <ul>
        <li><strong>Compile-Time vs. Runtime</strong>: <code>const</code> can be initialized with a value determined at runtime or compile-time, while <code>constexpr</code> must be initialized with a value that can be determined at compile-time.</li>
        <li><strong>Optimization</strong>: <code>constexpr</code> allows for more aggressive optimizations since the value is guaranteed to be known at compile-time, whereas <code>const</code> may still involve runtime evaluation.</li>
        <li><strong>Usage in Functions</strong>: <code>constexpr</code> can be applied to functions, allowing them to be used in compile-time expressions, while <code>const</code> is generally used for variables.</li>
    </ul>
    <h3>4. Practical Example</h3>
    <pre><code>#include &lt;iostream&gt;
const int getValue() {
    return 42;  // This function returns a constant, but it is not evaluated at compile-time.
}
constexpr int getConstexprValue() {
    return 42;  // This function is evaluated at compile-time if possible.
}
int main() {
    const int x = getValue();         // x is a constant, but the value is determined at runtime.
    constexpr int y = getConstexprValue();  // y is a constant and is evaluated at compile-time.

    int arr[x];  // Error: x is not a compile-time constant.
    int arr2[y]; // OK: y is a compile-time constant.

    std::cout &lt;&lt; x &lt;&lt; " " &lt;&lt; y &lt;&lt; std::endl;
    return 0;
}
</code></pre>
    <h3>5. When to Use</h3>
    <ul>
        <li>Use <code>const</code> when you want to define a variable that should not be modified after initialization, but its value might not be known until runtime.</li>
        <li>Use <code>constexpr</code> when you need to ensure that a variable or function is evaluated at compile-time, which is useful for compile-time constants, array sizes, and template arguments.</li>
        </ul>
<h2>Typecasting in C++</h2>
<p>Typecasting in C++ refers to converting a variable from one data type to another. This can be done in two main ways: implicit (automatic) typecasting and explicit typecasting.</p>
<h3>1. Implicit Typecasting</h3>
<p>Also known as automatic type conversion, implicit typecasting occurs when the compiler automatically converts one data type to another. This usually happens when you assign a value of one type to a variable of another type.</p>
<pre><code>
int a = 5;
double b = a; // 'a' is implicitly converted from int to double
</code></pre>
<p>In the above example, the integer <code>a</code> is implicitly converted to a double when assigned to <code>b</code>.</p>
<h3>2. Explicit Typecasting</h3>
<p>Explicit typecasting is when you manually convert a variable from one type to another. There are several ways to perform explicit typecasting in C++:</p>
<h4>a. C-style Cast</h4>
<p>The C-style cast is the simplest form of casting. It is performed by placing the desired type in parentheses before the variable.</p>
<pre><code>
int a = 5;
double b = (double)a; // Explicitly cast 'a' to double
</code></pre>
<h4>b. C++-style Casts</h4>
<p>C++ provides four types of casts that are more specific and safer than the C-style cast:</p>
<ul>
    <li><b>static_cast:</b> Used for most type conversions, such as converting between related types (e.g., converting <code>int</code> to <code>double</code>).</li>
</ul>
<pre><code>
int a = 5;
double b = static_cast&lt;double&gt;(a);
</code></pre>
<ul>
    <li><b>dynamic_cast:</b> Used for safely casting pointers or references to classes up and down the inheritance hierarchy. It's mostly used with polymorphic types (types with virtual functions).</li>
</ul>
<pre><code>
class Base { virtual void func() {} };
class Derived : public Base {};
Base* basePtr = new Derived;
Derived* derivedPtr = dynamic_cast&lt;Derived*&gt;(basePtr); // Safe downcast
</code></pre>
<ul>
    <li><b>const_cast:</b> Used to add or remove the <code>const</code> qualifier from a variable.</li>
</ul>
<pre><code>
const int a = 10;
int* b = const_cast&lt;int*&gt;(&a);
</code></pre>
<ul>
    <li><b>reinterpret_cast:</b> Used for low-level casts that might reinterpret the bits of the value, such as casting between unrelated pointer types.</li>
</ul>
<pre><code>
int* a = new int(10);
char* b = reinterpret_cast&lt;char*&gt;(a); // Reinterprets the memory address as a char pointer
</code></pre>
<h3>Summary</h3>
<ul>
    <li><b>Implicit Typecasting</b> is automatic and usually safe.</li>
    <li><b>Explicit Typecasting</b> requires the developer to specify the type conversion, using C-style casts or the more precise C++-style casts (<code>static_cast</code>, <code>dynamic_cast</code>, <code>const_cast</code>, and <code>reinterpret_cast</code>).</li>
</ul>
<p>Each cast type in C++ has specific use cases and restrictions, making them safer and more suitable for certain tasks than the generic C-style cast.</p>
</body>
</html>