**Exercise 1-9** Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank.

**筆記:**\
這次這個練習比起前幾個稍微難上一點，不過看懂這段程式碼，對未來寫程式將會很有幫助。\
Exercise1-9.c 的這程式一樣以EOF做為結尾字元，所以，迴圈部分與前面並無太大差異。不
過迴圈裡的程式碼就與之前的程式碼就稍有不同了。我在迴圈裡用到了isprinted這樣一個變
數，並用這個變數來判斷當前這一連串空白字元是否曾被印過，這種變數我們稱之為 flag 。

**Brief explination**\
This exercise is slightly harder than exercises appeared before. However,this exercise is helpful
for your coding in the future. \
Exercise 1-9.c treat EOF as the end of the input as before. So, the loop is similar. But, the code
in the block is different. I used a variable called isprinted to decide whether the series of blanks
are printed. We call this kind of usage of variable flag.
