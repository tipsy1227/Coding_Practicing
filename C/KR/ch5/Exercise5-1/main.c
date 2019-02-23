#include <stdio.h>
#include "getint.h"

#define MAXBUF 100

int main(){
	int n, i;
	char buf[MAXBUF];

	if(getint(&n) > 0)
		printf("%d\n", n);
	return 0;
}
