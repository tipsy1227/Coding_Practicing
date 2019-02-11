#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);    /* mygetline: read a line into s, return length */

/* copy its input to its output */
int main(){
	int len;	/* current line length */
	char line[MAXLINE];		/* current input line */

	while((len=mygetline(line, MAXLINE))>0)
		printf("%s", line);
	return 0;
}

/* mygetline: read a line into s, return length */
int mygetline(char s[], int lim){
	int c, i, result;

	i=0;
	result = 1;
	while(result){
		if(i>=lim-2)
			result = 0;
		else if((c=getchar())==EOF)
			result = 0;
		else if(c=='\n')
			result = 0;
		else{
			s[i] = c;
			++i;
		}
	}

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
