**Exercise 1-9** Write a program to copy its input to its output, replacing each tab by \\t,
each backspace by \\b, and each backslash by \\\\. This makes tabs and backspaces visible in
an unambiguous way.

**筆記:**\
這個練習題不像上一個程式那麼複雜，這次我們只需要判斷現在拿在手上的字元是不是tab，backspace或是反斜線，
就可以作相應的動作。比較有必要注意的是當我們要印出一個反斜線時，我們要用兩個 \\ 來表示，故兩個反斜線則
需要四個 \\ 來表示。

**Brief explination:**\
This exercise is simpler than the previous one. This time we just need to decide what's in our hand
and print the corresponding string.\
One thing to notice is that when we want to print a single backslash, we need to write it as \\\\ . So,
if we want to print two backslashes, we have to write \\\\\\\\ .
