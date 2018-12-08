**Exercise 1-2.** Experiment to find out what happens when printf's argument
string contains \c, where c is some character not listed above.

**筆記:**\
這個程式寫了一個未定義的跳脫字元'\c'，我在編譯時跑出了下面的"警告":
<pre>
Exercise1-2.c:3:10: warning: unknown escape sequence '\c' [-Wunknown-escape-sequence]
        printf("\c");
                ^~
</pre>
不過，因為是"警告"而不是"錯誤"，所以仍然會產生執行檔，而它的執行結果會印出"c"。

**Brief explanation:**\
This program us a undefined escape sequence '\c', I get this when I compile this code:
<pre>
Exercise1-2.c:3:10: warning: unknown escape sequence '\c' [-Wunknown-escape-sequence]
        printf("\c");
                ^~
</pre>
However, it is a "warring" rather than "error", so compiler still generates an executable
file,  and it will print "c" after being run.
