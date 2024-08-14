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
</body>
</html>