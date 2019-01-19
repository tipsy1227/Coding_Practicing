#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);
void remove_trail(char line[]);

/* remove trailing spaces from each line of input, and delete entirely blank lines */
int main(){
	int len;	/* current line length */
	char line[MAXLINE];		/* current input line */

	while((len=mygetline(line, MAXLINE))>0){
		remove_trail(line);
		printf("%s", line);
	}
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

void remove_trail(char s[]){
	int end, c, i;
	//find the end of this line
	for(i=0; (end=s[i])!='\0'&&end!='\n'; ++i)
		;

	//find the beginning of the trailing spaces
	for(;(c=s[i-1])==' '||c=='\t'; --i)
		;

	if(i>0 && end =='\n'){
		s[i] = end;
		++i;
	}
	s[i]='\0';
}
