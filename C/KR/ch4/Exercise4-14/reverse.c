#include <stdio.h>
#include <string.h>
#include "swap.h"

void reverse(char []);

int main(){
	char s[100] = "!dlrow ,olleH";

	reverse(s);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[]){
	int i, j, len = strlen(s);

	for(i=0, j=len-1; i<j; i++, j--)
		swap(s, i, j);
}
