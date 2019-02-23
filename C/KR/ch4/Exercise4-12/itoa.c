#include "itoa.h"

/* itoa: convert integer n into string */
void itoa(int n, char s[], int end){
	static int i = 0;
	if(n < 0){
		s[i++] = '-';
		++end;
		n = -n;
	}
	if(n / 10)
		itoa(n/10, s, end+1);
	else
		s[end] = '\0';
	s[i++] = n%10+'0';
}
