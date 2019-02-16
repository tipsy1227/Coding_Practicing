void ungetch(char);

/* ungets: push back an entire string onto the input */
void ungets(char s[]){
	int i;
	for(i=0; s[i]!='\0'; i++)
		;

	for(;i>=0; i--)
		ungetch(s[i]);
}
