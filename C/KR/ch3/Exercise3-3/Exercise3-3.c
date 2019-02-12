#include <stdio.h>
#include <ctype.h>

#define MAXBUF 1000    /* maximum characters of input */

void expand(char s1[], char s2[]);    /* expand: expands shorthand notations like a-z int the string s1 into
                                         equivalent complete list abc...xyz in s2 */

int main(){
	int c, i;
	char s[MAXBUF], t[MAXBUF/3*26+MAXBUF%3];

	i = 0;
	while((c=getchar()) != EOF)
		s[i++] = c;
	s[i]='\0';

	expand(s, t);
	printf("%s", t);
	return 0;
}

void expand(char s1[], char s2[]){
	int c, d, e, f, i, j;

	i = j = 0;
	if(s1[0] == '-'){
		s2[j++] = '-';
		++i;
	} 
	for(; (c=s1[i])!='\0'; ++i)
		if(c == '-'){
			e = s1[i-1];
			d = s1[i+1];
			if(e<d && ((isdigit(e)&&isdigit(d))||(islower(e)&&islower(d))||(isupper(e)&&isupper(d))))
				for(f=e+1; f<d; f++)
					s2[j++]=f;
			else
				s2[j++] = '-';
		} else
			s2[j++] = c;
	s2[j]='\0';
}
