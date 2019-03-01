#include <stdio.h>
#include <ctype.h>

int atoi(char *s);

/* convert input string into a integer and print it out */
int main(){
	char s[100];

	scanf("%s", s);
	printf("%d\n", atoi(s));
	return 0;
}

/* atoi convert string s to int */
int atoi(char *s){
	int val;
	int sign;

	while(isspace(*s))    /* skip white space */
		s++;
	sign = (*s=='-')? -1: 1;
	if(*s=='+' || *s=='-')
		s++;
	for(val=0; isdigit(*s); s++)
		val = 10*val+(*s-'0');
	if(*s == '.')
		s++;
	return sign * val;
}
