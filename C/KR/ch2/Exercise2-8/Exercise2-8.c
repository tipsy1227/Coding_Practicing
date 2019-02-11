#include <stdio.h>

void show_binary(int x);       /* prints out the binary form of integer x */
int rightrot(unsigned int x, int n);    /* returns the value of the integer x rotated to the right by n bit 
                                           positions */

/* right rotate the integer x by n bits */
int main(){
	int x, n;
	scanf("%d %d", &x, &n);

	show_binary(x);
	show_binary(rightrot(x, n));

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

int rightrot(unsigned int x, int n){
	return x>>n | x<<(sizeof(int)*8-n);
}
