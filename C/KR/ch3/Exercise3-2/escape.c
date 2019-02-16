#include <stdio.h>

#define MAXLINE 1000    /* maximum input line size */

int mygetline(char line[], int maxline);    /* mygetline: read a line into s, return length */
void escape(char s[], char t[]);            /* escape: converts newline and tab into visible escape \n and \t */

/* copies input to output and converts newline and tab into \n and \t */
int main(){
	int c, len;
	char s[MAXLINE], t[MAXLINE*2];

	while((len=mygetline(s, MAXLINE))>0){
		escape(s, t);
		printf("%s\n", t);
	}
	return 0;
}

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

void escape(char s[], char t[]){
	int c, i, j;

	for(i=j=0; (c=s[i])!='\0'; i++)
		switch(c){
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		default:
			t[j++] = c;
			break;
		}
	t[j] = '\0';
}
