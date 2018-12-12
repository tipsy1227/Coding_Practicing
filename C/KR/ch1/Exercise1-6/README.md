**Exercise 1-6** Verify the expression getchar()!=EOF is 0 or 1.

**筆記:**\
getchar()!=EOF 是一個關係運算式，他的結果要嘛成立，要嘛就是不成立。以這個運算式來舉例，
getchar()拿到的字元要嘛是EOF(End-of-file)，要嘛不是EOF，只有兩種可能。而C的關係運算式
則用數字0, 1來代表這兩種可能，分別是0代表不成立, 1代表成立。\
所以在Exercise1-6.c的執行過程中，當我們輸入不是EOF的字元時，它的輸出即為1(成立)；反之，
當我們輸入EOF時，它的輸出結果即為0(不成立)。留意到當我們輸入複數個字元時，只有第一個字
元會被程式讀取到。\
(p.s. 在linux, MacOs這些Unix-like的系統上，EOF的輸入為ctrl+d；而在Windows系統上，
EOF的輸入則為ctrl+z)

**Brief explination**\
getchar()！=EOF is a relational expression. Its result is either True or False.
In this case, the character getchar() takes in is either EOF(End-of-file) or not
EOF. There are only two possibilities. Moreover, relational expressions in C use
number 0and 1 to represent the two possibilities. 0 represents False, and 1
represents True.\
Therefore, during the execution of Exercise1-6.c, if we enter a character
which is not EOF, the result will be 1(True). On other hands, if we enter EOF, the
result will be 0(False). Note that if the input includes multiple characters, only the
first character will be read.\
(p.s. In Unix-like system, for example, Linux or MacOs, the character EOF is
entered by ctrl-d. And in Windows, the character EOF is entered by ctrl-z.)
