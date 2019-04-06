#include <stdio.h>
#include "rwlines.h"

char linearr[MAXLINES][MAXLEN];

void qsort(char lineptr[][MAXLEN], int left, int right);

/* sort input lines */
int main(){
	int nlines;
	if((nlines=readlines(linearr, MAXLINES)) >= 0){
		qsort(linearr, 0, nlines-1);
		writelines(linearr, nlines);
		return 0;
	} else{
		printf("error: input too big to sort\n");
		return 1;
	}
}
