#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>
//#include<math.h>

int main()
{
	puts("判断一个数是不是素数");

	uint32_t number;

	bool is_prime = true;

	puts("请输入一个正整数：");

	scanf_s("%" SCNu32, &number);

	if (number <= 1)
	{
		is_prime = false;
	}
	else
	{
		for (uint32_t index = 2; index * index <= number; index++)
		{
			if (number % index == 0)
			{
				is_prime = false;
				break;
			}
		}
	}

	if (is_prime)
	{
		printf("%" PRIu32 "是素数\n", number);
	}
	else
	{
		printf("%" PRIu32 "不是素数\n", number);
	}

	return 0;
}