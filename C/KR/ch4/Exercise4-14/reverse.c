#include <string.h>

/* swap: swap the position i j in s */
#define swap(s, i, j)    \
{                        \
	int tmp = s[i];      \
	s[i] = s[j];         \
	s[j] = tmp;          \
}

/* reverse: reverse string s */
void reverse(char s[]){
	int i, j, len = strlen(s);

	for(i=0, j=len-1; i<j; i++, j--)
		swap(s, i, j);
}
