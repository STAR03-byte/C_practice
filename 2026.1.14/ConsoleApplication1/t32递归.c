#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdlib.h>

uint32_t factoral(uint32_t n, uint32_t acc);

uint32_t fib(uint32_t n);

int main(void)
{
	uint32_t number = 5;

	printf("%" PRIu32"的阶乘是%" PRIu32 "\n", number, factoral(5, 1));

	printf("斐波那契数列%" PRIu32 "项的结果和是：%" PRIu32 "\n", number, fib(10));

	return 0;
}

uint32_t factoral(uint32_t n, uint32_t acc)
{
	if (n == 0)
	{
		return acc;
	}
	else
	{
		return factoral(n - 1, n * acc);
	}
}

uint32_t fib(uint32_t n)
{
	//迭代方法
	if (n <= 1)
	{
		return n;
	}
	else
	{
		uint32_t fib_2 = 1;
		uint32_t fib_1 = 0;
		uint32_t fib_n = 0;

		for (uint32_t i = 0; i < n; ++i)
		{
			fib_n = fib_1 + fib_2;
			fib_2 = fib_1;
			fib_1 = fib_n;
		}
		
		return fib_n;
	}
}