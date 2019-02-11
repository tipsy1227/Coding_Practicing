#include <stdio.h>

#define MAXINPUT 1000    /* maximum number of characters can be entered*/

int any(char s1[], char s2[]);    /* return the first location in the string s1 where any character form the s2
                                     occurs, or -1 if s1 contains no characters from s2 */
int has(char ch, char s[]);       /* decide if string s has ch*/

/* print out the location of the first symbol appears in the input, or -1 if input contains no symbols */
int main(){
	int c, i;
	char s[MAXINPUT];
	char symbols[30] = "!#$%&'()*+,-./:;<=>?@[\\]^_`|}~";

	i = 0;
	while((c=getchar()) != EOF)
		s[i++] = c;
	s[i] = '\0';

	printf("%d\n", any(s, symbols));
	return 0;
}

int any(char s1[], char s2[]){
	int c, i;

	for(i=0; (c=s1[i])!='\0'; i++)
		if(has(c, s2))
			return i;
	return -1;
}

int has(char ch, char s[]){
	int c, i;
	for(i=0; (c=s[i])!='\0'; i++)
		if(c == ch)
			return 1;
	return 0;
}
