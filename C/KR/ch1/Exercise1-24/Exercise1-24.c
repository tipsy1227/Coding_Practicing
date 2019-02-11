#include <stdio.h>

#define SLASH 1
#define ONE_LINE_COMMENT 2
#define MULTIPLE_LINE_COMMENT 3
#define STRING 4
#define CHARACTER 5
#define STAR 6

/* check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces */
int main(){
	int c, status, nparen, nbracket, nbrace, nquote, ndquote, ncomment;

	status = 0;
	nparen = nbracket = nbrace = nquote = ndquote = ncomment = 0;
	while((c=getchar()) != EOF){
		if(status == 0){
			if(c == '(')
				++nparen;
			else if(c == '[')
				++nbracket;
			else if(c == '{')
				++nbrace;
			else if(c == ')')
				--nparen;
			else if(c == ']')
				--nbracket;
			else if(c == '}')
				--nbrace;
			else if(c == '/')
				status = SLASH;
			else if(c == '\"'){
				++ndquote;
				status = STRING;
			} else if(c == '\''){
				++nquote;
				status = CHARACTER;
			}
		} else if(status == SLASH){
			if(c == '/')
				status = ONE_LINE_COMMENT;
			else if(c == '*'){
				++ncomment;
				status = MULTIPLE_LINE_COMMENT;
			} else
				status = 0;
		} else if(status == STRING){
			if(c == '\"'){
				--ndquote;
				status = 0;
			}
		} else if(status == CHARACTER){
			if(c == '\''){
				--nquote;
				status = 0;
			}
		} else if(status == ONE_LINE_COMMENT){
			if(c=='\n')
				status = 0;
		} else if(status == MULTIPLE_LINE_COMMENT){
			if(c == '*')
				status = STAR;
		} else if(status == STAR){
			if(c == '/'){
				--ncomment;
				status = 0;
			}else
				status = MULTIPLE_LINE_COMMENT;
		}
	}

	if(nparen != 0)
		printf("unbalanced parentheses\n");
	if(nbracket != 0)
		printf("unbalanced brackets\n");
	if(nbrace != 0)
		printf("unbalanced braces\n");
	if(nquote != 0)
		printf("unbalanced quote\n");
	if(ndquote != 0)
		printf("unbalanced double quotes\n");
	if(ncomment != 0)
		printf("unbalanced multiple-line comment\n");
	return 0;
}
