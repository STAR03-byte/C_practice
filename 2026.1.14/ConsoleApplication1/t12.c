#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main(void)
{
	uint8_t sum = 0;

	char input;

	while (true)
	{
		puts("ÇëÊäÈëÒ»¸ö×Ö·û£º");

		scanf_s(" %c", &input, 1);

		if (input == 'q')
		{
			break;
		}

		sum += input - '0';
	}

	printf("Sum = %"PRIu8"\n", sum);

	return 0;
}