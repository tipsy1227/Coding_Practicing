#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>    /* for atoi() */

#define MAXOP 100       /* max size of operand or operator */
#define MAXLINE 1000    /* max size of line */
#define NUMBER '0'      /* signal that a number was found */

int mygetline(char [], int limit);
void push(double);
double pop(void);

/* reverse Polish calculator (getline version) */
int main(){
	int len, type = 0;
	int i, j, c, d;
	double op2;
	char line[MAXLINE];
	char s[MAXOP];

	while((len=mygetline(line, MAXLINE))>0){
		i=0;
		while(type!='\n'){
			int j, c;
			while((s[0]=c=line[i++])==' ' || c=='\t')
				;
			s[1] = '\0';
			if(!isdigit(c)&& c!='.' && c!='+' && c!='-')
				type = c;
			else if(c=='+' || c=='-'){
				d = c;
				if(!isdigit(c=line[i]))
					type = d;
			} else{
				j=0;
				if(isdigit(c))
					while(isdigit(s[++j]=c=line[i++]))
						;
				if(c == '.')
					while(isdigit(s[++j]=c=line[i++]))
						;
				s[j] = '\0';
				--i;
				type = NUMBER;
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
			case '\n':
				printf("\t%g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
			}
		}
	}
	return 0;
}
