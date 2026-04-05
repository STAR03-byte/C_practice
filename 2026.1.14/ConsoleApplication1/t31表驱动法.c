#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

#define MONTH_COUNT 12
#define LEVEL_COUNT 11

int is_leap_year(int year);
int get_days_in_month(int month, int year);

char grade_level(int score);

int main(void)
{
	int res_days = get_days_in_month(3, 2026);

	printf("%d\n", res_days);

	char score_level = grade_level(100);

	printf("%c\n", score_level);

	return 0;
}

int is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int get_days_in_month(int month, int year)
{
	const int days_in_month[MONTH_COUNT] = { 31,is_leap_year(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };

	return days_in_month[month - 1];
}

char grade_level(int score)
{
	const char level[LEVEL_COUNT] = { 'F','F','F','F','F','F','D','C','B','A','A'};

	if (score < 0 || score>100)
	{
		return 'x';
	}

	return level[score / 10];
}