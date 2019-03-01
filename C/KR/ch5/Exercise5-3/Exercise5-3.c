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
	int i, j;

	for(i=0; s[i]!='\0'; i++)
		;
	for(j=0; (s[i+j]=t[j])!='\0'; j++)
		;
	return s;
}
