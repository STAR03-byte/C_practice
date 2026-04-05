#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	puts("打印金字塔图案");

	uint32_t level;

	puts("请输入层数：");

	scanf_s("%" SCNu32, &level);

	for (uint32_t i = 0; i < level; i++)
	{
		uint32_t space = level - (i + 1);

		printf("这是第%" PRIu32 "层:", i + 1);

		for (uint32_t j = 0; j < space; j++)
		{
			printf("  ");
		}

		for (uint32_t j = 0; j < i + 1; j++)
		{
			printf("%" PRIu32 " ", j + 1);
		}

		for (uint32_t j = i; j > 0; j--)
		{
			printf("%" PRIu32 " ", j);
		}

		printf("\n");

	}

	return 0;
}