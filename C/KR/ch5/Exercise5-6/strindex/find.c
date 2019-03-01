#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
int strindex(char *source, char *seacchfor);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines maching pattern */
int main(){
	char line [MAXLINE];
	int found = 0;

	while(mygetline(line, MAXLINE) > 0){
		if(strindex(line, pattern) >= 0){
			printf("%s", line);
			found++;
		}
	}
	return found;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim){
	int c, i;

	for(i=0; i<lim-2 && (c=getchar())!=EOF && c!='\n'; ++i)
		*(s+i) = c;

	if(c!=EOF){
		*(s+i) = c;
		++i;
	}
	*(s+i) = '\0';

	// keep taking characters until it is EOF or '\n'
	while(c!=EOF && c!='\n'){
		c=getchar();
		i++;
	}
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t){
	int i;
	char *u;
	for(u=s; *u!='\0'; u++){
		for(i=0; *(t+i)!='\0'&&*(u+i)==*(t+i); i++)
			;
		if(i>0 && *(t+i)=='\0')
			return u-s;
	}
	return -1;
}
