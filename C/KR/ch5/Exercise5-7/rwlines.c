#include <stdio.h>
#include <string.h>
#include "rwlines.h"

int mygetline(char s[], int lim);

/* readlines: read input lines */
int readlines(char lineptr[][MAXLEN], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len=mygetline(line, MAXLEN)) > 0)
		if(nlines>=maxlines)
			return -1;
		else{
			line[len-1] = '\0'; /* delete newlines */
			strcpy(lineptr[nlines++], line);
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char lineptr[][MAXLEN], int nlines){
	int i;
	for(i=0; i<nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* mygetline: reads a line into s, return its lenth */
int mygetline(char s[], int lim){
	int c, i;

	for(i=0; i<lim-2 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	if(c!=EOF){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	// keep taking characters until it is EOF or '\n'
	while(c!=EOF && c!='\n'){
		c=getchar();
		i++;
	}
	return i;
}
