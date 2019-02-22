#include <stdio.h>

void reverse(char []);
void swap(char [], int i, int j);

int main(){
	char s[100] = "!dlrow ,olleH";

	reverse(s);
	printf("%s\n", s);
	return 0;
}

void reverse(char s[]){
	static int i = 0, j = 0;
	char tmp;

	if(s[j]=='\0')
		return;

	tmp = s[j++];
	reverse(s);
	s[i++] = tmp;
}
