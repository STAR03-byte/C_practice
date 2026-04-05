#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

typedef struct Date {
	uint16_t day;
	uint16_t month;
	uint16_t year;
}Date;

typedef struct Person {
	char name[50];
	uint16_t age;
	uint16_t height;
}Person;

int main(void)
{
	Date tody = { 22,2,2026 };

	printf("%" PRIu16 "-%" PRIu16 "-%" PRIu16 "\n", tody.year, tody.month, tody.day);

	Date* date_ptr = &tody;

	printf("%" PRIu16 "-%" PRIu16 "-%" PRIu16 "\n", date_ptr->year, date_ptr->month, date_ptr->day);

	return 0;
}