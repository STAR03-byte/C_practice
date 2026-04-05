#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()

{
	uint32_t number;

	uint32_t sum_of_squares = 0;

	puts("请输入一个整数N，我们将计算从1——N的所有整数的平方和");

	scanf_s("%" PRIu32, &number);

	for (uint32_t index = 1; index <= number; index++)
	{
		sum_of_squares += index * index;
	}

	printf("平方和=%" PRIu32 "\n", sum_of_squares);

	return 0;
}