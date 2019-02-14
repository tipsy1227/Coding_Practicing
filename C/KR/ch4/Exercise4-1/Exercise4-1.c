#include <stdio.h>

#define MAXBUF 1000

int strrindex(char s[], char t[]);    /* returns the position of the rightmost occurrence of t in s, or -1 if there
                                        is none */

/* find the right most occurrence of input in s, or -1 if there is none */
int main(){
	int c;
	char s[MAXBUF] = "Hello, world";
	char t[MAXBUF];

	scanf("%s", t);
	printf("%d\n", strrindex(s, t));
	return 0;
}

int strrindex(char s[], char t[]){
	int i, j, k, p;

	p=-1;
	for(i=0; s[i]!='\0'; i++){
		for(j=i,k=0; t[k]!='\0'&&s[j]==t[k]; j++,k++)
			;
		if(k>0 && t[k]=='\0')
			p = i;
	}
	return p;
}
