#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char *s){
	int c, d;

	while((*s=c=getch())==' ' || c=='\t')
		;
	*(s+1) = '\0';
	if(!isdigit(c) && c!='.' && c!='+' && c!='-')
		return c;    /* not a number */
	if(c=='+' || c=='-'){
		d = c;
		if((c=getch()) != EOF)
			ungetch(c);
		if(!isdigit(c))
			return d;
	}
	if(isdigit(c))
		while(isdigit(*++s=c=getch()))
			;
	if(c == '.')
		while(isdigit(*++s=c=getch()))
			;
	*s = '\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}
