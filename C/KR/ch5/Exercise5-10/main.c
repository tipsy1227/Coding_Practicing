#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[]){
	int type, op2;
	while(--argc){
		type = getop(*++argv);
		switch(type){
		case NUMBER:
			push(atof(*argv));
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
			if(op2 != 0)
				push(pop()/op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if(op2 != 0)
				push(pop()%op2);
			else
				printf("error: zero divisor\n");
			break;
		case UNKNOWN:
			printf("error: unknown operator or operand \"%s\"\n", *argv);
			return 1;
		}
	}
	printf("\t%d\n", pop());
	return 0;
}
