#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "calc.h"

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
	int c, i = 0;

	c = s[0];
	if(!strcmp(s, "+") || !strcmp(s, "-") || !strcmp(s, "*") || !strcmp(s, "/") || !strcmp(s, "%"))
		return c;    /* an operator */
	if((c=='+'||c=='-'))
		i++;

	for(; (c=s[i])!='\0'; i++)
		if(!isdigit(c))
			return UNKNOWN;
	return NUMBER;
}
