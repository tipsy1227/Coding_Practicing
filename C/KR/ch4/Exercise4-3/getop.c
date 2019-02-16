#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
	int i, c, d;

	while((s[0]=c=getch())==' ' || c=='\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c!='.' && c!='+' && c!='-')
		return c;    /* not a number */
	if(c=='+' || c=='-'){
		d = c;
		if((c=getch()) != EOF)
			ungetch(c);
		if(!isdigit(c))
			return d;
	}
	i=0;
	while(isdigit(s[++i]=c=getch()))
			;
	s[i] = '\0';
	if(c!=EOF)
		ungetch(c);
	return NUMBER;
}
