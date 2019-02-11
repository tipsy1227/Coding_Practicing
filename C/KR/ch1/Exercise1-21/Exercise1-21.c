#include <stdio.h>

#define TABSTOP 8

int nextpos(int pos); /* nextpos: make the pos loop from 1 to 8 */

/* replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing */
int main(){
	int c, nb, pos;

	nb = 0;
	pos = 1;
	while((c=getchar()) !=EOF){
		if(c == ' '){
			if(pos == TABSTOP){
				putchar('\t');
				nb = 0;
			} else
				++nb;
			pos = nextpos(pos);
		} else{
			for(; nb>0; --nb)
				putchar(' ');
			putchar(c);
			if(c=='\n' || c=='\t')
				pos = 1;
			else
				pos = nextpos(pos);
		}
	}
	return 0;
}

int nextpos(int pos){
	if(pos == TABSTOP)
		pos = 1;
	else
		++pos;
	return pos;
}
