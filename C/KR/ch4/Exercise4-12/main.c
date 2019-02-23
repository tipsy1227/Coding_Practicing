#include <stdio.h>
#include "itoa.h"

#define MAXBUF 12

int main(){
	int n;
	char s[MAXBUF];

	scanf("%d", &n);
	itoa(n, s, 1);
	printf("%s\n", s);
	return 0;
}
