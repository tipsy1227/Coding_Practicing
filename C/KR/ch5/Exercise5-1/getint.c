#include <stdio.h>
#include <ctype.h>
#include "getint.h"

/* getint: get next integer from input into *pn */
int getint(int *pn){
	int c, d, sign;

	while(isspace(c=getch()))    /* skip white space */
		;
	if((c=='+'||c=='-')){
		if(!isdigit(d=getch())){
			ungetch(d);
			ungetch(c);
			return 0;
		} else
			ungetch(d);
	} else if(!isdigit(c) && c!=EOF){
		ungetch(c);    /* it's not a number */
		return 0;
	}
	sign = (c=='-')? -1:1;
	if(c=='+' || c=='-')
		c=getch();
	for(*pn = 0; isdigit(c); c=getch())
		*pn = 10*(*pn)+ (c-'0');
	*pn *= sign;
	if(c == EOF)
		ungetch(c);
	return c;
}
