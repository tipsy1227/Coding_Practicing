#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);

/* print lines which are longer than 80 */
int main(){
	int len;	/* current line length */
	char line[MAXLINE];		/* current input line */

	while((len=mygetline(line, MAXLINE))>0)
		if(len > 80)
			printf("%s", line);
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
