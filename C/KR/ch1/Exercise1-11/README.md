**Exercise 1-11** How would you test the word count program? What kinds of input are
most likely to uncover bugs if there are any?

**筆記:**\
當我們要測試一個程式有沒有bug時，其中一個作法是極端值檢驗，意思是用那些比較極端的輸入值來
檢驗程式是否存在bug。以書中的word-count程式來舉例，我們就可以試試當我輸入只有一個單字時，
甚至是一個單字都沒有時，程式的結果是否正確。而這個程式看起來除了因為字數太多造成 nl, nw,
nc 這些計數器溢位會使得結果不正確以外，貌似沒有其它bug了。

**Brief explination:**\
When we are going to test if there are bugs in a program, one of the various methods is
**Boundary value test**. It means that test a program with the boundary value. For example,
in the word-count program provided by the book, we can test it with only one word in the
input or input has no word.\
Except when the input contains too many words result in the counter in the program overflow, there seems
to be no other bug in it.
