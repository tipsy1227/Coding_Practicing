#include <stdio.h>

#define MAXNUM 10

int binsearch(int x, int v[], int n);

int main(){
	int t, p, v[MAXNUM] = {11, 15, 17, 19, 25, 39, 50, 51, 60, 90};

	scanf("%d", &t);
	if((p=binsearch(t, v, MAXNUM)) >= 0)
		printf("%d\n", p);
	else
		printf("Not found\n");
	return 0;
}

int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low < high){
		mid = (low+high)/2;
		if(x > v[mid])
			low = mid+1;
		else
			high = mid;
	}
	if(x != v[low])
		return -1;
	else
		return low;
}
