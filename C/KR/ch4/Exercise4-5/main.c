#include <stdio.h>
#include <stdlib.h>    /* for atoi() */
#include <math.h>

#define MAXOP 100     /* max size of operand or operator */
#define NUMBER '0'    /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* reverse Polish calculator */
int main(){
	int type;
	double op2, tmp;
	char s[MAXOP];

	while((type=getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
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
		case 's':
			push(sin(pop()));
			break;
		case 'e':
			push(exp(pop()));
			break;
		case 'p':
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '\n':
			printf("\t%g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
