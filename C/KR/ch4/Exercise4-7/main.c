#include <stdio.h>

int getch(void);
void ungets(char []);

/* copies its input to its output */
int main(){
	int c;
	ungets("Hello, world:\n");
	while((c=getch()) != EOF)
		putchar(c);
	return 0;
}
