**Exercise 1-21** Write a program entab that replaces strings of
blanks by the minimum number of tabs and blanks to achieve the 
same spacing. Use the same tab stops as fro detab. When either 
a tab or a single blank wouls suffice to reach a tab stop, which 
should be given preference?

**筆記:**\
這個練習題比起前面的題目難上一點，你必需判斷出哪些空白字元是可以
被 tab 所取代，哪些不可以，在 Exercise1-21.c 中，我用了兩個變數
 nb 和 pos 來判斷是否要以tab取代掉某些空白字元。注意到，這個程式
的 nb 和上一個程式的 nb 所代表的意義並不一樣。

**Brief explination:**\
This exercise is more complicated than before. You have to decide 
which blanks can be replaced by tab, which can't. In Exercise1-21.c, 
I use two variables nb and pos for the decision.\
Note that the nb in this program and that in the last program have a 
different meaning.
