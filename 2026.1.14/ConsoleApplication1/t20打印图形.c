#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	puts("打印图形，并且输入边长");

	uint32_t size;

	scanf_s("%" SCNu32, &size);

	for (uint32_t index = 0; index < size; index++)
	{
		for (uint32_t j = 0; j <= index; j++)
		{
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}