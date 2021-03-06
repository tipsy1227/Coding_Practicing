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

	sign = n;    /* record sign */
	i = 0;
	do{    /* generate digits in reverse order */
		s[i++] = absolute(n%10)+'0';    /* get next digit */
	} while((n/=10) != 0);    /* delete it */
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int i, j;
	char tmp;
	for(i=0, j=strlen(s)-1; i<j; i++, j--)
		tmp=s[i], s[i]=s[j], s[j]=tmp;    /* swap s[i] and s[j] */
}

int absolute(int n){
	return (n>0)? n: -n;
}
