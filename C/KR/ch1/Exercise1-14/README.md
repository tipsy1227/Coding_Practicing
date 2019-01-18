**Exercise 1-14** Write a program to print a histogram of the frequencies of different
characters in its input.

**筆記:**\
我與上一個習題一樣用了一個陣列來儲存長柱体的長度，不一樣的是，這個練習題的長柱体長度是根據字元的出現頻率而增加，
而且陣列的變數個數也只有95個，剛好是可列印字元的個數。\
注意到，可列印字元的ASCII編號從十進位的32到126，總共是95個，Exercise1-14.c 裡，freq[0] 記錄空白字元(ASCII:32)的
出現頻率，freq[1]記錄'!'(ASCII:33)的出現頻率，依此類推，freq[94] 記錄'~'(ASCII:126)的出現頻率。

**Brief explination:**\
This time, I use an array for storing the lengths of histograms just like the previous exercise.
Differently, the lengths of histograms are decided by the frequencies of characters in this exercise.
And, the number of variable in the array is 95, which is the number of printable characters.\
Note that the value of printable character in ASCII is from 32 to 126 in decimal, which is 95
characters in total. In Exercise1-14.c, freq[0] records the frequency of blank(ASCII:32), freq[1]
records the frequency of'!'(ASCII:33), and so on. freq[94] records the frequency of '~'(ASCII:126).
