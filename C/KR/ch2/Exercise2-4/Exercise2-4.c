#include <stdio.h>

#define MAXINPUT 1000    /* maximum number of characters can be entered*/

void squeeze(char s1[], char s2[]);    /* delete each character in s1 that matched any character in the s2 */
int has(char ch, char s[]);            /* decide if string s has ch*/

/* delete all punctuation character from the input */
int main(){
	int c, i;
	char s[MAXINPUT];
	char unwanted[30] = "!#$%&'()*+,-./:;<=>?@[\\]^_`|}~";

	i = 0;
	while((c=getchar()) != EOF)
		s[i++] = c;
	s[i] = '\0';

	squeeze(s, unwanted);
	printf("%s", s);
	return 0;
}

void squeeze(char s1[], char s2[]){
	int c, i, j, k;
	for(k=i=0; (c=s1[i])!='\0'; i++)
		if(!has(c, s2))
			s1[k++] = c;
	s1[k] = '\0';
}

int has(char ch, char s[]){
	int c, i;
	for(i=0; (c=s[i])!='\0'; i++)
		if(c == ch)
			return 1;
	return 0;
}
