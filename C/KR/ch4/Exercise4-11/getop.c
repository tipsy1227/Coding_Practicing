#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
	int i, d;
	static int bufp = 0;
	static int c;

	while((s[0]=(bufp)?(bufp=0),c:(c=getch()))==' ' || c=='\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c!='.' && c!='+' && c!='-')
		return c;    /* not a number */
	if(c=='+' || c=='-'){
		d = c;
		c=(bufp)?(bufp=0),c:(c=getch());
		bufp = 1;
		if(!isdigit(c))
			return d;
	}
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=(bufp)?(bufp=0),c:(c=getch())))
			;
	if(c == '.')
		while(isdigit(s[++i]=c=(bufp)?(bufp=0),c:(c=getch())))
			;
	s[i] = '\0';
	if(c!=EOF)
		bufp = 1;
	return NUMBER;
}
