#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	uint32_t start_number;

	puts("请输入一个数字，开始倒数：");

	scanf_s("%"SCNu32, &start_number);

	for (uint32_t index = start_number; index >=1; index--)
	{
		printf("%" PRIu32 "\n", index);

		Sleep(1000);
	}

	return 0;
}