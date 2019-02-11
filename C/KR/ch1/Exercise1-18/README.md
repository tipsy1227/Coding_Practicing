**Exercise 1-18.** Write a program to remove trailing blanks and tabs from each line of input, 
and to delete entirely blank lines.

**筆記:**\
在 Exercise1-18.c 中，與前幾題相同，我們使用getline來一行一行的處理輸入，而remove\_trail這個函式會先找到當前這一行
結尾空白的開頭位置，再將原本此行的結尾字元('\n'&'\0')取代掉這個位置的字元。而當取代的位置為０(即此行開頭)時，意謂
著這此行原本是一空白行，故結果不應包含此行。\
注意到，若使用printf列印字串，當字串開頭位置為'\0'，則printf不會印出任何字元。

**Brief explination:**\
In Exercise1-18.c, same as before, we use getline for dealing with input one line by one line. The function 
remove\_trail find the position of the beginning of trailing blanks and tabs in the current line. After that, 
replace this character with the end of this line('\n'&'\0').If the position to be replaced is 0(the beginning 
of this line), it means that this line is an entirely blanks line.\
Note that, when we use printf to print a string, and this string begins with '\0', then printf doesn't print anything.
