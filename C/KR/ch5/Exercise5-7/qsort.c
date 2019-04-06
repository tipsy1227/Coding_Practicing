#include <stdio.h>
#include <string.h>
#include "rwlines.h"

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char v[][MAXLEN], int left, int right){
	int i, last;
	void swap(char v[][MAXLEN], int, int);

	if(left >= right)    /* do nothing if array conatains */
		return;          /* fewer than two elements */
	swap(v, left, (left+right)/2);
	last = left;
	for(i=left+1; i<=right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char v[][MAXLEN], int i, int j){
	if(i == j)
		return ;
	char temp[MAXLEN];
	strcpy(temp, v[i]);
	strcpy(v[i], v[j]);
	strcpy(v[j], temp);
}
