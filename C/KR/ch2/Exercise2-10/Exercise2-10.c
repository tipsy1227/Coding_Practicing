#include <stdio.h>

int lower(int c);    /* convert c to lower case; ASCII only */

/* copy its input to its output and convert upper cases to lower cases */
int main(){
	int c;
	while((c=getchar()) != EOF)
		putchar(lower(c));

	return 0;
}

int lower(int c){
	return (c>='A'&&c<='Z')? c-'A'+'a': c;
}
