#include <stdio.h>

#define IN 1
#define OUT 0

#define MAXWORD 10000	/*maximum number of words*/

/*print a histogram of the lengths of words in its input.(vertical version)*/
int main(){
	int c, state, max_len, nw, i;
	int len[MAXWORD];

	for(i=0; i<MAXWORD; i++)
		len[i] = 0;

	max_len = nw = 0;
	state = OUT;
	//count length of each word and record the length of the longest word
	while((c=getchar()) != EOF)
		if(c!=' ' && c!='\n' && c!='\t'){
			state = IN;
			len[nw]++;
		} else if(state == IN){
			state = OUT;
			if(len[nw]>max_len)
				max_len = len[nw];
			nw++;
		}

	//print histograms
	for(i=0; i<max_len; i++){
		int j;

		for(j=0; j<nw; j++)
			if(i<len[j])
				putchar('*');
			else
				putchar(' ');
		putchar('\n');
	}
}
