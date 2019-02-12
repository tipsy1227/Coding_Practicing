#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int maxline);    /* mygetline: read a line into s, return length */
void deescape(char s[], char t[]);          /* deescape: converts \n and \t into newline and tab */

/* copies input to output and converts \n and \t into newline and tab */
int main(){
	int c, len;
	char s[MAXLINE], t[MAXLINE];

	while((len=mygetline(s, MAXLINE))>0){
		deescape(s, t);
		printf("%s", t);
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

void deescape(char s[], char t[]){
	int c, i, j, isescape;

	isescape = 0;
	for(i=j=0; (c=s[i])!='\0'; i++)
		if(isescape){
			switch(c){
				case 'n':
					t[j++] = '\n';
					break;
				case 't':
					t[j++] = '\t';
					break;
				default:
					t[j++] = '\\';
					t[j++] = c;
					break;
			}
			isescape = 0;
		} else if(c == '\\')
			isescape = 1;
		else
			t[j++] = c;
	t[j] = '\0';
}
