#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

#define EMPLOYRES_COUNT 5	
void update_salary(uint32_t* salaries, uint32_t increment);
void print_emp(uint32_t* salaries);
uint32_t calc_bonus(uint32_t salary);
uint32_t* find_hightest_salary(const uint32_t* salaries);

int main(void)
{
	uint32_t salaries[EMPLOYRES_COUNT] = { 3000,4000,5000,6000,7000 };

	uint32_t increment = 1000;

	puts("初始工资为：");
	print_emp(salaries);

	update_salary(salaries, increment);

	puts("最终工资为：");
	print_emp(salaries);

	uint32_t* highest = find_hightest_salary(salaries);

	printf("最高工资为:%" PRIu32 "\n", *highest);

	printf("最高工资的年终奖为：%"PRIu32 "\n", calc_bonus(*highest));

	return 0;
}

void update_salary(uint32_t* salaries, uint32_t increment)
{
	for (size_t i = 0; i < EMPLOYRES_COUNT; i++)
	{
		salaries[i] += increment;
	}
}

void print_emp(uint32_t* salaries)
{
	for (size_t i = 0; i < EMPLOYRES_COUNT; i++)
	{
		printf("%" PRIu32 " ", salaries[i]);
	}
	printf("\n\n");
}

uint32_t calc_bonus(uint32_t salary)
{
	return salary / 10;
}

uint32_t* find_hightest_salary(const uint32_t* salaries)
{
	const uint32_t* highest = salaries;

	for (size_t i = 0; i < EMPLOYRES_COUNT; i++)
	{
		if (salaries[i] > *highest)
		{
			highest = &salaries[i];
		}
	}
	return highest;
}