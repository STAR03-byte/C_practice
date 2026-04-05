#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main(void)
{
	int matrix[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	// ptr 是一个指向“包含3个int数据的数组”的指针
	// 数组本身就是一个指针，用这个指针再指向一个（一维）数组，就定义了多维数组的指针形式
	int(*ptr)[3] = matrix;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}

	return 0;
}