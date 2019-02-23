#include <stdio.h>
#include "reverse.h"

int main(){
	char s[100] = "!dlrow ,olleH";

	reverse(s);
	printf("%s\n", s);
	return 0;
}
