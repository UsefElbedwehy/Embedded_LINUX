<html>
<body>
<h2>
Function overloading:
</h2>
<p>Function overloading is a feature of object-oriented programming where two or more functions can have the same name but different parameters. When a function name is overloaded with different jobs it is called Function Overloading. In Function Overloading “Function” name should be the same and the arguments should be different.</p>
<p>If multiple functions having same name but parameters of the functions should be different is known as Function Overloading.</p>
<pre><code>int multiply(int a, int b)</code>
<code>float multiply(float a, float b)</code></pre>
<p>Run the followin command to make sure that they are defference.</p>
<div style="background-color: #f5f5f5; padding: 10px; border-radius: 4px; border: 1px solid #ddd;">
<pre><code>gobjdump -t ex1.out | grep -i mul</code></pre>
</div>
<p>Output:</p>
<pre>
<code>
000000000000133a l     F .text  0000000000000019              _GLOBAL__sub_I__Z8multiplyii
000000000000122c g     F .text  000000000000004a              _Z8multiplyff
00000000000011e9 g     F .text  0000000000000043              _Z8multiplyii
</code></pre>
<h2>NULL vs nullptr</h2>
<p>
In C++, NULL and nullptr are both used to represent a null pointer, but they differ in important ways. The introduction of nullptr in C++11 addresses several issues that arise from using NULL.
</p>
<ul>
<li>NULL:
<ul>
    <li>NULL is typically defined as 0 or ((void*)0).</li>
    <li>Since NULL is an integer constant, it can lead to ambiguities when overloaded functions are involved. This can cause unintended behavior if the compiler chooses the wrong overload.</li>
</ul>
</li>
<li>nullptr:
    <ul>
    <li>nullptr is a keyword introduced in C++11. It has its own type, std::nullptr_t, which can only be converted to pointer types.</li>
    <li>Snullptr provides type safety because it is not an integer and is not convertible to anything other than a pointer type. This avoids the ambiguity problems associated with NULL.</li>
    </ul>
</li>
</ul>
<pre>
<code>
#include <iostream>

void foo(int x) {
    std::cout << "Called foo(int)" << std::endl;
}

void foo(void* p) {
    std::cout << "Called foo(void*)" << std::endl;
}

int main() {
    foo(NULL);    // Might call foo(int) depending on the compiler, leading to ambiguity.
    foo(nullptr); // Calls foo(void*), as intended.
}
</code>
</pre>
<pre>
Called foo(int)
Called foo(void*)
</pre>
</body>
</html>