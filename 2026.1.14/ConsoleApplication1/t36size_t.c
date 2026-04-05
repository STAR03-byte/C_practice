#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main(void)
{
	int32_t arrays[] = { 10,20,30,40,50,60,70,80,90,100 };

	int32_t* ptr_arrays = arrays;

	size_t arrays_size = sizeof(arrays) / sizeof(arrays[0]);

	puts("原始数组：");

	for (size_t i = 0; i < arrays_size; ++i)
	{
		printf("%" PRId32 " ", arrays[i]);
	}
	printf("\n");

	for (size_t i = 0; i < arrays_size; ++i)
	{
		*(ptr_arrays + i) += 5;
	}

	puts("修改后的数组：");

	for (size_t i = 0; i < arrays_size; ++i)
	{
		printf("%" PRId32 " ", *(ptr_arrays + i));
	}
	
	printf("\n");

	return 0;
}