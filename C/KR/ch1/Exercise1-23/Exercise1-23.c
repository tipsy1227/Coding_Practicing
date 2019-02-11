#include <stdio.h>

#define SLASH 1
#define ONE_LINE_COMMENT 2
#define MULTIPLE_LINE_COMMENT 3
#define STRING 4
#define CHARACTER 5
#define STAR 6

/* remove all comments from a C program */
int main(){
	int c, status;

	status = 0;
	while((c=getchar()) != EOF){
		if(status == 0){
			if(c == '/')
				status = SLASH;
			else{
				putchar(c);
				if(c == '\"')
					status = STRING;
				else if(c == '\'')
					status = CHARACTER;
			}
		} else if(status == SLASH){
			if(c == '/')
				status = ONE_LINE_COMMENT;
			else if(c == '*')
				status = MULTIPLE_LINE_COMMENT;
			else{
				putchar('/');
				putchar(c);
				status = 0;
			}
		} else if(status == STRING){
			putchar(c);
			if(c == '\"')
				status = 0;
		} else if(status == CHARACTER){
			putchar(c);
			if(c == '\'')
				status = 0;
		} else if(status == ONE_LINE_COMMENT){
			if(c == '\n'){
				putchar(c);
				status = 0;
			}
		} else if(status == MULTIPLE_LINE_COMMENT){
			if(c == '*')
				status = STAR;
		} else if(status == STAR){
			if(c == '/')
				status = 0;
			else
				status = MULTIPLE_LINE_COMMENT;
		}
	}
	return 0;
}
