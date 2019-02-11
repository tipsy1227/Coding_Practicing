#include <stdio.h>

#define MAXLINE 11 /* MAXLINE is n+1. n is 10 in this case*/

int mygetline(char line[], char pre[], int maxline);    /* mygetline: read a line into s with the prefix of string pre, return length of line */
void reverse(char s[]);                                 /* reverse: reverse string s */
void swap(char s[], int i, int j);                      /* swap: swap two character s[i], s[j] in string s */
int hasspace(char s[]);                                 /* hasspace: decise if string s has space(blank or tab) */

/* fold long input lines into two or more shorter lines */
int main(){
	int len;                 /* current line length */
	char line[MAXLINE];      /* current input line */
	char remain[MAXLINE];    /* the remain part of last input line */

	remain[0] = '\0';
	while((len=mygetline(line, remain, MAXLINE)) > 0)
		printf("%s\n", line);
	return 0;
}

int mygetline(char s[], char pre[], int lim){
	int c, i, j;

	for(i=0; pre[i]!='\0'; ++i)
		s[i] = pre[i];

	for(; (c=getchar())!=EOF && c!='\n' && i<lim-1; ++i)
		s[i] = c;
	s[i] = '\0';

	j = 0;
	if(c!='\n' && c!=EOF){
		if(hasspace(s)){
			--i;
			while((c=s[i])!=' ' && c!='\t'){
				pre[j] = c;
				++j;
				--i;
			}
		} else{
			pre[j] = c;
			++j;
		}
	}
	pre[j] = '\0';
	reverse(pre);
	s[i] = '\0';
	return i;
}

int hasspace(char s[]){
	int c, i;
	for(i=0; (c=s[i])!='\0'; ++i)
		if(c == '\t' || c == ' ')
			return 1;
	return 0;
}

void reverse(char s[]){
	int i, j;
	for(i=0; s[i]!='\0'; ++i)
		;
	--i;
	j=0;
	while(j<i){
		swap(s, j, i);
		++j;
		--i;
	}
}

void swap(char s[], int j, int i){
	char tmp = s[j];
	s[j] = s[i];
	s[i] = tmp;
}
