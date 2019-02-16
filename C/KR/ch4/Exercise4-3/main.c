#include <stdio.h>
#include <stdlib.h>    /* for atoi() */

#define MAXOP 100     /* max size of operand or operator */
#define NUMBER '0'    /* signal that a number was found */

int getop(char []);
void push(int);
int pop(void);

/* reverse Polish calculator */
int main(){
	int type;
	int op2;
	char s[MAXOP];

	while((type=getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atoi(s));
			break;
		case '+':
			push(pop()+pop());
			break;
		case '*':
			push(pop()*pop());
			break;
		case '-':
			op2 = pop();
			push(pop()-op2);
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop()/op2);
			else
				printf("error: zero divisor\n");
				break;
		case '%':
			op2 = pop();
			push(pop()%op2);
			break;
		case '\n':
			printf("\t%d\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
