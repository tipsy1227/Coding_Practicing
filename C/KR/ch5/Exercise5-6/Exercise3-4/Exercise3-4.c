#include <stdio.h>

void itoa(int n, char s[]);    /* itoa: convert n to characters in s */
void reverse(char s[]);        /* reverse: reverse the string s */
int absolute(int n);           /* absolute: return the absolute value of integer n */

/* convert a number into string */
int main(){
	int n;
	char s[12];

	scanf("%d", &n);
	itoa(n, s);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[]){
	int i, sign;
	char *t = s;

	sign = n;    /* record sign */
	i = 0;
	do{    /* generate digits in reverse order */
		*t++ = absolute(n%10)+'0';    /* get next digit */
	} while((n/=10) != 0);    /* delete it */
	if(sign < 0)
		*t++ = '-';
	*t = '\0';
	reverse(s);
}

void reverse(char s[]){
	char *t;

	for(t=s; *t!='\0'; t++)
		;
	for(t=t-1; s<t; s++, t--)
		tmp=*s, *s=*t, *t=tmp;    /* swap *s and *t */
}

int absolute(int n){
	return (n>0)? n: -n;
}
