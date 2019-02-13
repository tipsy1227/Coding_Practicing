#include <stdio.h>

void itob(int n, char s[], int b);    /* itob: converts n to base b characters in s */
void reverse(char s[]);               /* reverse: reverses the string s */
int symbol(int n);                    /* symbol: returns the symbol of integer n, which is a digit or an alphabet. 
                                         this function can only handle from base 2 to 36*/
int absolute(int n);                  /* absolute: returns the absolute value of integer n */

/* converts a number into base 2, 8, 16 */
int main(){
	int n, b;
	char s[33];

	scanf("%d", &n);

	itob(n, s, 2);
	printf("%s\n", s);

	itob(n, s, 8);
	printf("%s\n", s);

	itob(n, s, 16);
	printf("%s\n", s);
	return 0;
}

void itob(int n, char s[], int b){
	int i, sign;

	sign = n;    /* record sign */
	i = 0;
	do{    /* generate digits in reverse order */
		s[i++] = symbol(n%b);    /* get next digit */
	} while((n/=b) != 0);    /* delete it */
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]){
	int i, j;
	char tmp;
	for(i=j=0; s[j]!='\0'; ++j)
		;
	--j;
	for(; i<j; ++i, --j)
		tmp=s[i], s[i]=s[j], s[j]=tmp;    /* swap s[i] and s[j] */
}

int symbol(int n){
	int c, m;
	if((m=absolute(n)) < 10)
		c = m+'0';
	else
		c = m-10+'A'; 
	return c;
}

int absolute(int n){
	return (n>0)? n: -n;
}
