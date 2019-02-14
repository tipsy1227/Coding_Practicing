#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char []);                   /* atof: convert strings to double */
int mygetline(char line[], int lim);    /* mygetline: read a line into s, return length */

/* rudimentary calculator */
int main(){
	double sum;
	char line[MAXLINE];

	sum = 0;
	while(mygetline(line, MAXLINE) > 0)
		printf("\t%g\n", sum+=atof(line));
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

double atof(char s[]){
	double val, power, p;
	int i, sign, sval, ssign;

	for(i=0; isspace(s[i]); i++)    /* skip white space */
		;
	sign = (s[i]=='-')? -1: 1;
	if(s[i]=='+' || s[i]=='-')
		i++;
	for(val=0.0; isdigit(s[i]); i++)
		val = 10.0*val+(s[i]-'0');
	if(s[i] == '.')
		i++;
	for(power=1.0; isdigit(s[i]); i++){
		val = 10.0*val+(s[i]-'0');
		power *= 0.1;
	}
	if(s[i]=='E' || s[i]=='e'){
		i++;
		ssign = (s[i]=='-')? -1: 1;
		if(s[i]=='+' || s[i]=='-')
			i++;
		for(sval=0; isdigit(s[i]); i++)
			sval = 10*sval+(s[i]-'0');
		p = (ssign>0)? 10.0: 0.1;
		for(;sval>0; sval--)
			power*=p;
	}
	return sign * val * power;
}
