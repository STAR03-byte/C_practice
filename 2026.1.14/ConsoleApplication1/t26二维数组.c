#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main()
{
	uint32_t number_arr[5][5] = {
		{1,2,3,4,5},
		{2,3,4,5,6},
		{3,4,5,6,7},
		{4,5,6,7,8},
		{5,6,7,8,9}
	};

	for (uint32_t i = 0; i < 5; i++)
	{
		for (uint32_t j = 0; j < 5; j++)
		{
			printf("%" PRIu32 " ",number_arr[i][j]);
		}
		
		puts("\n");
	}

	return 0;
}