**Exercise 1-1.** Run the "hello, world" program on your system. Experiment
with leaving out parts of the program, to see what error messages you get.

**筆記:**\
若照著書KR書上的程式碼打，你可能會發現這個程式在編譯時會跑出下面的"警告":
<pre>
Exercise1-1.c:2:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
main(){
^
</pre>
雖然這個警告並不影響編譯器產生執行檔也不會導致程式執行錯誤，但是我之後都會在main()前面
加上"int"來去除這個警告。而且加上"int"將會使得這個函數的定義更完整，也更清晰。

**Brief explination**\
If your code is same as the code in KR, you may find the following "warning":
<pre>
Exercise1-1.c:2:1: warning: type specifier missing, defaults to 'int' [-Wimplicit-int]
main(){
^
</pre>
Although the warning didn't make the compiler failing to generate an executable file and
didn't affect the result during execution, I will add an "int" before the main() from now
on to make this definition of function more clear and complete.
