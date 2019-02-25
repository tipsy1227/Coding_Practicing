#include <stdio.h>
#include <ctype.h>
#include "getfloat.h"

#define MAXBUF 3

/* getfloat: get next floating point number from input into *pn */
int getfloat(float *pn){
	int c, d, sign, i;
	float pow = 1.0;
	char buf[MAXBUF];

	while(isspace(c=buf[0]=getch()))    /* skip white space */
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.'){
		ungetch(c);    /* it's not a number */
		return 0;
	}
	i = 0;
	sign = (c=='-')? -1:1;
	if(c=='+' || c=='-')
		c = buf[++i] = getch();
	if(c == '.')
		c = buf[++i] = getch();
	for(; i>=0; i--)
		ungetch(buf[i]);
	if(!isdigit(c))
		return 0;
	if((c=getch())=='+' || c=='-')
		c=getch();
	for(*pn=0.0; isdigit(c); c=getch())
		*pn = 10*(*pn)+(c-'0');
	if(c=='.'){
		c=getch();
		for(; isdigit(c); c=getch()){
			*pn = 10*(*pn)+(c-'0');
			pow *= 10;
		}
	}
	*pn = (*pn)/pow*sign;
	if(c == EOF)
		ungetch(c);
	return c;
}
