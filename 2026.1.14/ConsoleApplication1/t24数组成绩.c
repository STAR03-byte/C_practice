#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<inttypes.h>

#define STUDENT_COUNT 5
int main()
{
	uint32_t grades[STUDENT_COUNT] = { 78,89,43,90,99 };

	uint32_t sum = 0;

	uint32_t max_grade = grades[0];

	uint32_t min_grade = grades[0];

	for (uint32_t index = 0; index < STUDENT_COUNT; index++)
	{
		sum += grades[index];

		if (grades[index] > max_grade)
		{
			max_grade = grades[index];
		}

		if (grades[index] < min_grade)
		{
			min_grade = grades[index];
		}
	}

	double average_grade = (double)sum / STUDENT_COUNT;

	printf("总成绩为：%" PRIu32 "\n", sum);

	printf("平均成绩为： %.2f\n", average_grade);

	printf("最高分为：%" PRIu32 "\n", max_grade);

	printf("最低分为：%" PRIu32 "\n", min_grade);

	return 0;
}