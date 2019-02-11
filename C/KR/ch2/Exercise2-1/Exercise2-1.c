#include <stdio.h>
#include <limits.h>
#include <float.h>

unsigned long two2pow(unsigned long int p);    /* two2pow: return the value of two to the power p */

/* determine the ranges of char, short, int and long variables, both signed and unsigned */
int main(){
	printf("standard header:\n");

	printf("\n");

	printf("char: %d-%d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char: %d-%d\n", 0, UCHAR_MAX);

	printf("short int: %d-%d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short int: %d-%d\n", 0, USHRT_MAX);

	printf("int: %d-%d\n", INT_MIN, INT_MAX);
	printf("unsigned int: %d-%u\n", 0, UINT_MAX);

	printf("long int: %ld-%ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long int: %d-%lu\n", 0, ULONG_MAX);

	printf("\n");

	printf("direct computation:\n");

	printf("\n");

	printf("char: %ld-%lu\n", -two2pow(sizeof(char)*8-1), two2pow(sizeof(char)*8-1)-1);
	printf("unsigned char: %d-%lu\n", 0, two2pow(sizeof(unsigned char)*8)-1);

	printf("short int: %ld-%lu\n", -two2pow(sizeof(short int)*8-1), two2pow(sizeof(short int)*8-1)-1);
	printf("unsigned short int: %d-%lu\n", 0, two2pow(sizeof(unsigned short int)*8)-1);

	printf("int: %ld-%lu\n", -two2pow(sizeof(int)*8-1), two2pow(sizeof(int)*8-1)-1);
	printf("unsigned int: %d-%lu\n", 0, two2pow(sizeof(unsigned int)*8)-1);

	printf("long int: %ld-%lu\n", -two2pow(sizeof(long int)*8-1), two2pow(sizeof(long int)*8-1)-1);
	printf("unsigned long int: %d-%lu\n", 0, two2pow(sizeof(unsigned long int)*8)-1);

}

unsigned long two2pow(unsigned long int p){
	int i;
	long int ans;

	ans = 1;
	for(i=0; i<p; i++)
		ans *= 2;
	return ans;
}
