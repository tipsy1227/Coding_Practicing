#include <stdio.h>
/* replace each string of blanks by a single blank. */
int main(){
	int c;
	int isprinted=0;
	while((c=getchar()) != EOF)
		if(c!=' '){
			if(isprinted)
				isprinted=0;
			putchar(c);
		} else if(!isprinted){
			isprinted=1;
			putchar(c);
		}
}
