#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(){
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while((len=mygetline(line, MAXLINE))>0)
		if(len > max){
			max = len;
			copy(longest, line);
		}
	if(max>0)
		printf("%s", longest);
	return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim){
	int c, i;

	for(i=0; i<lim-2 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	if(c!=EOF){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	// keep taking characters until it is EOF or '\n'
	while(c!=EOF && c!='\n'){
		c=getchar();
		i++;
	}
	return i;
}

/* copy: copy 'from' into 'to' */
void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i]=from[i]) != '\0')
		++i;
}
