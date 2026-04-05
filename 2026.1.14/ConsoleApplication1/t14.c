#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	int32_t number;

	uint32_t sum = 0;

	puts("请输入一系列正整数来计算他们的和");
	puts("可以输入负数，但它们不会被加入到计算当中");
	puts("输入0以结束，并显示出总和");

	while (true)
	{
		puts("请输入数字：");

		scanf_s("%" PRId32, &number);

		if (number < 0)
		{
			continue;
		}
		if (number == 0)
		{
			break;
		}

		sum += number;
	}

	printf("Sum=%" PRIu32 "\n", sum);

	return 0;
}