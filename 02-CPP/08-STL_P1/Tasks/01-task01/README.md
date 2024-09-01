<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Explanation of Constructors and Destructors in C++</title>
</head>
<body>
    <h1>Explanation of Constructors and Destructors in C++</h1>
    
<p>The behavior where multiple constructors and destructors are called, including a destructor being called before any significant action in the <code>main</code> function, is related to how the C++ compiler handles temporary objects and the <em>copy elision</em> feature.</p>
    
<h2>What’s Happening in Your Code:</h2>
    
<ol>
        <li><strong>String user_name = "Usef Elbedwehy";</strong>
            <ul>
                <li><strong>Temporary Object Creation</strong>: A temporary <code>String</code> object is created from the C-style string <code>"Usef Elbedwehy"</code> using the parameterized constructor.</li>
                <li><strong>Copy Constructor</strong>: The temporary <code>String</code> object is then copied to the <code>user_name</code> object using the copy constructor because of the assignment (<code>=</code>) operator in the initialization.</li>
                <li><strong>Destructor Call for the Temporary Object</strong>: After the copy is made, the temporary <code>String</code> object is destroyed, leading to the first destructor call.</li>
            </ul>
        </li>
        <li><strong>Printing <code>user_name</code></strong>: 
            <p>The <code>operator&lt;&lt;</code> is called to print <code>user_name</code>, but since this is after the temporary object has already been destroyed, it works on the copied object (<code>user_name</code>).</p>
        </li>
        <li><strong>Exiting <code>main</code></strong>: 
            <p>The destructor for <code>user_name</code> is called at the end of the scope, leading to the second destructor call.</p>
        </li>
    </ol>
    
<h2>Why Do You See Two Constructor and Destructor Calls?</h2>
    
<p>Given the command <code>g++ -g -fno-elide-constructors main.cpp -o out1.out && ./out1.out</code>:</p>
    
<ul>
        <li><strong>First Constructor</strong>: When you initialize <code>user_name</code> with <code>"Usef Elbedwehy"</code>, the parameterized constructor is called to create a temporary <code>String</code> object.</li>
        <li><strong>Copy Constructor</strong>: The temporary <code>String</code> object is then copied to <code>user_name</code> using the copy constructor.</li>
    <li><strong>First Destructor</strong>: After copying, the temporary <code>String</code> object is destroyed, invoking the destructor.</li>
<li><strong>Second Destructor</strong>: At the end of <code>main</code>, the destructor for <code>user_name</code> is called.</li>
</ul>
    
<h2>Example Output Explanation:</h2>
<pre>
Parameterized constructor
Copy constructor
Default destructor
Usef Elbedwehy
Default destructor
</pre>
    
<ul>
        <li><strong>Parameterized constructor</strong>: When the temporary object is created.</li>
        <li><strong>Copy constructor</strong>: When the temporary object is copied to <code>user_name</code>.</li>
        <li><strong>First Default destructor</strong>: When the temporary object is destroyed.</li>
        <li><strong>Second Default destructor</strong>: When <code>user_name</code> is destroyed.</li>
    </ul>
    
<h2>Key Points:</h2>
    
<ul>
        <li><strong>Copy Elision</strong>: By default, modern C++ compilers use a technique called <em>copy elision</em> to optimize away unnecessary copy and move operations. It can result in fewer constructor/destructor calls.</li>
        <li><strong><code>-fno-elide-constructors</code> Flag</strong>: Disables copy elision, which forces the compiler to strictly follow the rules for copy construction and assignment, leading to the observed behavior.</li>
    </ul>
    
<h2>Without the <code>-fno-elide-constructors</code> Flag:</h2>
    <p>If you remove the <code>-fno-elide-constructors</code> flag, you may only see one constructor and one destructor call because the compiler will optimize away the temporary object and directly construct <code>user_name</code>.</p>

</body>
</html>
