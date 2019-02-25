#include <stdio.h>

int strend(char *, char *);

int main(){
	printf("%d\n", strend("Hello, World!", "orld!"));
	return 0;
}

int strend(char *s, char *t){
	int i, j;
	i = j = 0;
	while(s[i]!='\0')
		i++;
	while(t[j]!='\0')
		j++;
	if(i<j)
		return 0;
	while(s[i]==t[j])
		i--, j--;
	return j < 0;
}
