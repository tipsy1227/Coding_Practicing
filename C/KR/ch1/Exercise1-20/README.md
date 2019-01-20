**Exercise 1-20** Write a program detab that replaces tabs in the input with the proper number of blanks to space
to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic
parameter?

**筆記:**\
因為 tab stop 是一個定值，所以我們不用特別宣告一個變數來儲存這個數字。\
這個練習題的重點在於如何知道每個 tab 所占的空間有多少，Exercise1-20.c 的作法是使用一個初始值為 TABSTOP 的變數 nb ，
當讀入一個 tab 時，再用這個 nb 來判斷應該印出幾個空白鍵。

**Brief explination:**\
Since tab stop is a constant, we don't need to declare a variable for storing this constant number.\
The point of this exercise is how many blanks should we print when we read a tab. In Exercise1-20.c, 
I use a variable nb which has an initial value of TABSTOP to evaluate how many blanks should print.
