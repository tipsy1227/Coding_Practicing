#include <stdio.h>

#define MAXBUF 100

char *mystrcat(char *, char *);

int main(){
	char s[MAXBUF] = "Hello";
	mystrcat(s, ", World!");
	printf("%s\n", s);
	return 0;
}

/* mystrcat: copies the string t to the end of s, return the address of the resulting string */
char *mystrcat(char *s, char *t){
	char *u = s;
	for(;*u!='\0'; u++)
		;
	while((*u=*t)!='\0')
		++u, ++t;
	return s;
}
