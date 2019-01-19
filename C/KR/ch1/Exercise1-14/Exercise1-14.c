#include <stdio.h>

#define MAXCHAR 95

/* print a histogram of the frequencies of characters */
int main(){
	int c, freq[MAXCHAR];
	int i;

	for(i=0; i<MAXCHAR; i++)
		freq[i] = 0;

	while((c=getchar()) != EOF){
		int p;
		//if it is a printable character
		if((p=c-32)>=0 || p<MAXCHAR)
			freq[p]++;
	}

	for(i=0; i<MAXCHAR; i++){
		int j, f;

		if((f=freq[i])>0){
			printf("%c: ", i+32);
			for(j=0; j<f; j++)
				putchar('*');
			putchar('\n');
		}
	}
}
