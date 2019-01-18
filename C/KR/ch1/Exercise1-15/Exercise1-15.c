#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float f2c(int fahr); /* convert Fahrenheit to Celsius */

/* print Fahrenheit-Celsius table */
int main(){
	int fahr;
	for(fahr=LOWER; fahr<=UPPER; fahr=fahr+STEP)
		printf("%3d %6.1f\n", fahr, f2c(fahr));
}

float f2c(int f){
	return (5.0/9.0)*(f-32);
}
