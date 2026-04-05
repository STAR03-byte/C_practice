#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<inttypes.h>

int main(void)
{
	uint32_t zombies[10] = { 2,4,3,7,45,46,32,687,87,342 };

	uint32_t plants[5] = { 23,43,53,64,654 };

	for (uint32_t i = 0; i < 10; i++)
	{
		printf("½©Ê¬ÊÇ£º%" PRIu32 "\t", zombies[i]);
	}

	puts("\n");

	for (uint32_t i = 0; i < 5; i++)
	{
		printf("Ö²ÎïÊÇ£º%" PRIu32 "\t", plants[i]);
	}

	return 0;
}