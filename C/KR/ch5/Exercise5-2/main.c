#include <stdio.h>
#include "getfloat.h"

int main(){
	float n;

	if(getfloat(&n) > 0)
		printf("f: %f\n", n);
	return 0;
}
