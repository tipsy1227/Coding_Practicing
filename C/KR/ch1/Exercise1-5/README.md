**Exercise 1-5.** Modify the temperature conversion program to print the table
in reverse order, that is, from 300 degrees to 0.

**筆記:**\
這個練習題的程式碼與之前幾個while迴圈的程式有著許多不同，不過其中一個比較值得
注意的是printf參數列裡的這段運算式:
<pre>
(5.0/9.0)\*(fahr-32)
</pre>
雖然\*右邊是一個整數運算式，但因為左邊的算式是小數運算式，所以編譯器會將整個
算式的結果視為一個小數。換句話說，編譯器會將較不精準或範圍較小的型態自動轉成
較精準或範圍較大的型態(e.g. short\<int\<float\<double)。

**Brief explination:**\
This exercise has a lot of difference with those earlier with while-loop.But,
the one should be  aware of is the expression in the argument list of printf:
<pre>
(5.0/9.0)\*(fahr-32)
</pre>
Although the right-hand side of the \* is an integer expression, the other side
of the \* is a floating-point expression. So the compiler will treat the result
of the whole expression as a float.(that's why we use %f) In other words, the
compiler will convert the type with less precision and small range into the type
with more precision and bigger range(e.g. short\<int\<float\<double).
