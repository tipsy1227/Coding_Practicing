#ifndef RWLINES_H
#define RWLINES_H

#define MAXLINES 5000
#define MAXLEN 1000

int readlines(char lineptr[][MAXLEN], int nlines);
void writelines(char lineptr[][MAXLEN], int nlines);

#endif
