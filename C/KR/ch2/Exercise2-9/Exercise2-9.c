#include <stdio.h>

void show_binary(int x);         /* prints out the binary form of integer x */
int bitcount(unsigned int x);    /* count 1 bits in x */

/* print out how many 1 bits are in x */
int main(){
	int x;
	scanf("%d", &x);

	show_binary(x);
	printf("%d\n", bitcount(x));
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

int bitcount(unsigned int x){
	int b;
	for(b=0; x>0; x&=x-1)
		++b;
	return b;
}
