#include <stdio.h>
#include <stdlib.h>    /* for atoi() */
#include <math.h>

#define MAXOP 100     /* max size of operand or operator */
#define NUMBER '0'    /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(){
	int type, enc_var=-1;
	double op2, var[26]={0}, r;
	char s[MAXOP];

	while((type=getop(s)) != EOF){
		if(enc_var && type!='='){
			push(var[enc_var-'A']);
			enc_var = 0;
		}
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
		case '=':
			if(enc_var){
				push(var[enc_var-'A']=pop());
				enc_var = 0;
			}else
				printf("error: invalid use of '='\n");
			break;
		case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J':
		case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T':
		case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
			enc_var = type;
			break;
		case 'r':
			push(r);
			break;
		case '\n':
			printf("\t%g\n", r=pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
