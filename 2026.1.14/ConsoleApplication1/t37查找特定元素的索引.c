#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

bool find_index_of_value(const int32_t* array, size_t size, int32_t target_value, size_t* index);

int main(void)
{
	int32_t values[] = { 10,20,30,40,50 };

	int32_t* start_ptr = values;

	size_t values_size = sizeof(values) / sizeof(values[0]);

	int32_t target_value = 30;

	int32_t* target_ptr = NULL;

	size_t index = 0;

	bool found = find_index_of_value(start_ptr, values_size, target_value, &index);

	//for (size_t i = 0; i < values_size; ++i)
	//{
	//	if (*(start_ptr + i) = target_value) {
	//		target_ptr = start_ptr + i;
	//		index = i;
	//		found = true;
	//		break;
	//	}
	//}

	if (found)
	{
		printf("元素%" PRId32 "的index为%zu\n", target_value, index);
	}
	else
	{
		puts("未找到!");
	}

	return 0;
}

bool find_index_of_value(const int32_t* array, size_t size, int32_t target_value, size_t* index)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (*(array + i) == target_value)
		{
			*index = i;
			return true;
		}
	}
	return false;
}