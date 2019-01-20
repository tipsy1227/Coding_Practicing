#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);    /* mygetline: read a line into s, return length */
void reverse(char []);                      /* reverse: reverse string s */
void swap(char [], int, int);               /* swap: swap two character s[i], s[j] in string s */


/* print lines which are longer than 80 */
int main(){
	int len;	/* current line length */
	char line[MAXLINE];		/* current input line */

	while((len=mygetline(line, MAXLINE))>0){
		reverse(line);
		printf("%s\n", line);
	}
	return 0;
}

int mygetline(char s[], int lim){
	int c, i;

	for(i=0; i<lim-2 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	if(c!=EOF && c!='\n'){
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

void reverse(char s[]){
	int i, j;

	for(i=0; s[i+1]!='\0'; i++)
		;
	j=0;

	// swap the first and the last, the second and the second-last, and so on
	while(j<i){
		swap(s, j, i);
		--i;
		++j;
	}
}

void swap(char s[], int j, int i){
	char tmp = s[j];
	s[j] = s[i];
	s[i] = tmp;
}
