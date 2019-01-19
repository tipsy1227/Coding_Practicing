#include <stdio.h>

#define IN 1
#define OUT 0

/* copy the input one word per line to the output */
int main(){
	int c, state;

	state = OUT;
	while((c=getchar()) != EOF)
		if(c!=' ' && c!='\n' && c!='\t'){
			state = IN;
			putchar(c);
		} else if(state == IN){
			state = OUT;
			putchar('\n');
		}
}
