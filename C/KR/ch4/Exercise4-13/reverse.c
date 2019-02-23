#include "reverse.h"

/* reverse: reverse string s */
void reverse(char s[]){
	static int i = 0, j = 0;
	char tmp;

	if(s[j]=='\0')
		return;

	tmp = s[j++];
	reverse(s);
	s[i++] = tmp;
}
