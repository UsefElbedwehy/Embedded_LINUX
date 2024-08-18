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
</body>
</html>
