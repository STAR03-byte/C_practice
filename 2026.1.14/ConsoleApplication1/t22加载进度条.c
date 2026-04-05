#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main()
{
	uint32_t toatal_steps = 100;

	puts("Downloading······");

	for (uint32_t i = 0; i <= toatal_steps; i++)
	{
		printf("\r[");

		for (uint32_t j = 0; j < i; j++)
		{
			printf("#");
		}

		for (uint32_t j = i; j < toatal_steps; j++)
		{
			printf(" ");
		}

		printf("]%" PRIu32 "%%", (i * 100) / toatal_steps);

		Sleep(100);
	}

	puts("\n处理完成！");

	system("pause");

	return 0;
}