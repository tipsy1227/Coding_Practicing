**Exercise 1-13.** Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more
challenging.

**筆記:**\
這個練習題的水平版本只需要把前一個練習題稍微更改一下即可完成。\
而垂直版本就相較難上一點，在 Exercise1-12\_ver.c 之中，我用了一個陣列來儲存各個單字的長度，
並記錄了最長的長度，用作最後印出長柱体時的結束條件。

**Brief explination:**\
Horizontal version of this exercise is simple. We can only change one line in the previous
exercise to finish it.\
However, the vertical version is much harder than the horizontal one. In Exercise1-12\_ver.c,
I use an array for storing lengths of words. And also record the length of the longest word
which I use it to be the end condition of the print.
