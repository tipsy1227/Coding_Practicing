#include <stdio.h>

void show_binary(int x);            /* prints out the binary form of integer x */
int invert(int x, int p, int n);    /* returns x with the n bits that begin at position p inberted */

/* inverts the left-half of input number */
int main(){
	int x, p, n;
	scanf("%d", &x);
	p = sizeof(int)*8-1;
	n = sizeof(int)*4;

	show_binary(x);
	show_binary(invert(x, p, n));

	return 0;
}

void show_binary(int x){
	int p;
	for(p=sizeof(int)*8-1; p>=0; --p){
		putchar((x>>p&1)+'0');
		if(p%4 == 0)
			putchar(' ');
	}
	putchar('\n');
}

int invert(int x, int p, int n){
	return x ^ (~(~0<<n)<<(p+1-n));
}
