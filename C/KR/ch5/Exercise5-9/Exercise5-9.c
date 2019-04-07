#include <stdio.h>

static char *daytab[2];
char a0[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char a1[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 30, 31, 31};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

/* show the result of day_of_year and month_day */
int main(){
	int year, month, day, yearday;

	*daytab = a0;
	*(daytab+1) = a1;

	year = month = day = yearday = 0;
	scanf("%d %d %d", &year, &month, &day);
	printf("%d\n", day_of_year(year, month, day));

	year = month = day = yearday = 0;
	scanf("%d %d", &year, &yearday);
	month_day(year, yearday, &month, &day);
	printf("%d %d\n", month, day);

	return 0;
}

/* day_of_year: set day of year from month & day, return 0 if the date is erroneous */
int day_of_year(int year, int month, int day){
	if(year<1 || month<1 || month>12 || day<1)
		return 0;

	int i, leap;

	leap = (year%4==0 && year%100!=0) || year%400==0;
	if(day > *(*(daytab+leap)+month))
		return 0;
	for(i=1; i<month; i++)
		day += *(*(daytab+leap)+i);
	return day;
}

/* month_day: set month, day from day of year, set *pmonth and *pday to 0 if the year or yearday is erroneous */
void month_day(int year, int yearday, int *pmonth, int *pday){
	if(year<1 || yearday<1){
		*pmonth = 0;
		*pday = 0;
		return;
	}

	int i, leap;

	leap = (year%4==0 && year%100!=0) || year%400==0;
	if(yearday > (leap? 366: 366)){
		*pmonth = 0;
		*pmonth = 0;
		return;
	}
	for(i=1; yearday>*(*(daytab+leap)+i); i++)
		yearday -= *(*(daytab+leap)+i);
	*pmonth = i;
	*pday = yearday;
}
