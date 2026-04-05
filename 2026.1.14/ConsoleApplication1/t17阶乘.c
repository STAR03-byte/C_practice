#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	uint32_t number;

	uint32_t factorial = 1;

	/*uint32_t sum = 1;*/

	puts("请输入一个正整数N，以计算N的阶乘:");

	scanf_s("%" SCNu32, &number);

	for (uint32_t index = 1; index <= number; index++)
	{

		/*sum *=factorial;

		factorial++;*/

		factorial *= index;
	}

	/*printf("%" PRIu32"!= %" PRIu32"\n", number, sum);*/
	printf("%" PRIu32"!= %" PRIu32"\n",number,factorial);

	return 0;
}