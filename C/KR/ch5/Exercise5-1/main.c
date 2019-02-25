#include <stdio.h>
#include "getint.h"

int main(){
	int n;

	if(getint(&n) > 0)
		printf("%d\n", n);
	return 0;
}
