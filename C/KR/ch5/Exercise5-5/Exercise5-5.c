#include <stdio.h>
#include <string.h>

#define MAXBUF 100

char *mystrncpy(char *, char *, int);
char *mystrncat(char *, char *, int);
int mystrncmp(char *, char *, int);

/* Implement the library functions strncpy, strncat, and strncmp */
int main(){
	char s1[MAXBUF] = "Hello, World";
	printf("%s\n", mystrncpy(s1, "HELLO", 5));

	char s2[MAXBUF] = "Hello, ";
	printf("%s\n", mystrncat(s2, "World!\n", 5));

	char s3[MAXBUF] = "Hello, World";
	char s4[MAXBUF] = "Hello, World!\n";
	printf("%d\n", mystrncmp(s3, s4, 12));
	return 0;
}

/* mystrncpy: copies at most n characters of t to s */
char *mystrncpy(char *s, char *t, int n){
	int i;

	for(i=0; i<n&&t[i]!='\0'; i++)
		s[i] = t[i];
	return s;
}

/* mystrncat: copies the string t to the end of s */
char *mystrncat(char *s, char *t, int n){
	int s_end, i;

	for(s_end=0; s[s_end]!='\0'; s_end++)
		;
	for(i=0; i<n&&(s[s_end+i]=t[i])!='\0'; i++)
		;
	return s;
}

/* mystrncmp: compares the string s and s, returns 0 if they are the same  */
int mystrncmp(char *s, char *t, int n){
	int i;
	for(i=0; i<n&&s[i]!='\0'&&t[i]!='\0'&&s[i]==t[i]; i++)
		;
	return s[i]-t[i];
}
