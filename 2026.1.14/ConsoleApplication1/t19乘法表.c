#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	uint32_t num;

	puts("请输入一个正整数，我们将为你生成乘法表");

	scanf_s("%" SCNu32, &num);

	printf("乘法表 %" PRIu32 "\n", num);

	for (uint32_t index = 1; index < 10; index++)
	{
		printf("%" PRIu32 " x %" PRIu32 " = %" PRIu32 "\n", num, index, num * index);
	}

	return 0;
}