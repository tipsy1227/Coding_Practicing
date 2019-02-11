#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line size */

int mygetline(char line[], int maxline);    /* mygetline: read a line into s, return length */
int ishex(int c);                          /* decide if c is a hexadecimal digit */
int htoi(char []);                          /* convert a string of hexadecimal digits into its equivalent integer value */

/* convert each of strings of hexadecimal digits into its equivalent interger value */
int main(){
	int len;	            /* current line length */
	char line[MAXLINE];		/* current input line */

	while((len=mygetline(line, MAXLINE))>0){
		printf("%d\n", htoi(line));
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
	if(c == '\n')
		++i;
	return i;
}

int htoi(char s[]){
	int c, i, value, v;

	value = 0;
	i = 0;
	if(s[0]=='0' && ((c=s[1])=='x'||c=='X'))
		i+=2;

	while(ishex(c=s[i])){
		if(isdigit(c))
			v = c-'0';
		else if(isupper(c))
			v = c-'A'+10;
		else
			v = c-'a'+10;
		value = value*16+v;
		++i;
	}
	return value;
}

int ishex(int c){
	return (c>='A'&&c<='F') || (c>='a'&&c<='A') || isdigit(c);
}
