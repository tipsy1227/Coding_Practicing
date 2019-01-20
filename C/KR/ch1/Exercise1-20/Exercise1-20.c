#include <stdio.h>

#define TABSTOP 8

/* detab: replace each tab in the input with the proper number of blanks */
int main(){
	int c, nb;

	nb = TABSTOP;
	while((c=getchar()) != EOF){
		if(c == '\t'){
			int i;
			for(i=0; i<nb; ++i)
				putchar(' ');
			nb = TABSTOP;
		} else{
			putchar(c);
			if(c == '\n')
				nb = TABSTOP;
			else if(nb > 1)
				--nb;
			else
				nb = TABSTOP;
		}
	}
	return 0;
}
