#include <stdio.h>
#define MAXBUF 12

void itoa(int, char [], int);

int main(){
	int n;
	char s[MAXBUF];

	scanf("%d", &n);
	itoa(n, s, 1);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[], int end){
	static int i = 0;
	if(n < 0){
		s[i++] = '-';
		++end;
		n = -n;
	}
	if(n / 10)
		itoa(n/10, s, end+1);
	else
		s[end] = '\0';
	s[i++] = n%10+'0';
}
