#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

int main(void)
{
	int32_t department1[] = { 101,102,103 };
	int32_t department2[] = { 201,202,203 ,204 };
	int32_t department3[] = { 301,302,303,305,306 };

	int32_t* department_ptrs[3] = { department1,department2,department3 };

	size_t  department_sizes[3] = {
		sizeof(department1) / sizeof(int32_t),
		sizeof(department2) / sizeof(int32_t),
		sizeof(department3) / sizeof(int32_t)
	};

	for (size_t i = 0; i < 3; ++i)
	{
		printf("Department %zu:", i + 1);
		for (size_t j = 0; j < department_sizes[i]; ++j)
		{
			//先访问最外层数组里面的指针元素，再在每个指针元素数组里面寻址访问；还是相当于访问二维数组。
			printf("%" PRId32 " ", department_ptrs[i][j]);
		}
		printf("\n");
	}
	return 0;
}