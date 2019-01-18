**Exercise 1-16** Revise the main routine of the longest-line program so it will correctly print
the length of arbitrarily long input lines, and as much as possible of the text.

**筆記:**\
如果你所使用的編譯環境是linux, macOS這類Unix-like的作業系統，第一個遇到的問題可能會是下列這個警告:
<pre>
Exercise1-16.c:5:5: error: conflicting types for 'getline'
int getline(char line[], int maxline);
    ^
</pre>
意思是 getline 這個函式被重復定義了，所以在 Exercise1-16.c 中，我把原本的 getline 取名為 mygetline 
來解決這個問題。\
在Exercise1-16.c中，注意到29行 i\<lim-2 這個邏輯運算式。因為任何字串的最後一個字元應為'\0'，所以s這個
陣列至多只能有 lim-1 個字元，即i為 lim-2 。故從書上原本不考慮輸入過多情況的 i\<lim-1 改成 i\<lim-2 。

**Brief explination:**\
If your compile environment is Linux or macOS(Unix-like operating system), the first problem you might 
encounter is that
<pre>
Exercise1-16.c:5:5: error: conflicting types for 'getline'
int getline(char line[], int maxline);
    ^
</pre>
It means that getline is redefined. In that case, I change all getline in Exercise1-16.c to mygetline 
to solve this problem.\
In Exercise1-16.c, note the logic expression i\<lim-2 at the 29th row. Cause the last character in a 
string should be '\0', in array s, there is at most lim-1 character, which means i is lim-2.So I change
the i\<lim-1 in the original program which doesn't consider the input being too much to i<lim-2.
