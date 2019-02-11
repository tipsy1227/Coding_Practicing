**Exercise 1-19.** Write a function reverse(s) that reverses the character string s. Use it to write a program
that reverses its input a line at a time.

**筆記:**\
在 Exercise1-19.c 中，我用了一個簡單的想法來反轉字串，把一個字串中的第一個字與最後一個字交換，第二個字與倒數第二個
字交換，依此類推，就可以把字串反轉過來。
注意到，為了使reverse這個函式可以簡單的達到程式目的，我將 Exercise1-19.c 的 getline 稍作更改，使得它不會將每一行的
換行字符儲存起來。

**Brief explination:**\
In Exercise1-19.c, I use a simple idea to reverse a string. Swap the first character and the last character, the 
second character and the second-last character, and so on. After that, we can easily get the reversed string.\
Note that, to make the function reverse rechieve the purpose of this exercise, I slightly change the function 
getline in Exercise1-19.c. Make it doesn't store the newline character of each line.
