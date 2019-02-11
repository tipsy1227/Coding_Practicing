#include <stdio.h>

void show_binary(int x);                    /* prints out the binary form of interger x */
int setbits(int x, int p, int n, int y);    /* returns x with the n bits that begin at position p set to the
                                               rightmost n bits of y */

/* set the left-half of x to the right-half of y */
int main(){
	int x, p, n, y;
	scanf("%d %d", &x, &y);
	p = sizeof(int)*8-1;
	n = sizeof(int)*4;

	show_binary(x);
	show_binary(y);
	show_binary(setbits(x, p, n, y));

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

int setbits(int x, int p, int n, int y){
	return (x&~(~(~0<<n)<<(p+1-n))) | ((y&~(~0<<n))<<(p+1-n));
}
