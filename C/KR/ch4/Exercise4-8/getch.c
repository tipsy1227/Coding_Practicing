#include <stdio.h>

#define BUFSIZE 100

char buf;    /* buffer for ungetch */
int isempty = 1;

/* getch: get a (possibly pushed back) character */
int getch(void){
	if(isempty)
		return getchar();
	isempty = 1;
	return buf;
}

/* ungetch: push character back on input */
void ungetch(int c){
	if(!isempty)
		printf("ungetch: too many characters\n");
	else{
		isempty = 0;
		buf = c;
	}
}
