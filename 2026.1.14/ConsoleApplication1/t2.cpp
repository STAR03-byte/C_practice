#include<stdio.h>
#include<stdint.h>
#include<inttypes.h> // 添加此头文件以定义PRId32

int main()
{
	int32_t myInt32 = INT32_MAX;

	uint32_t myUInt32 = UINT32_MAX;

	uint64_t myUInt64 = UINT64_MAX;

	int_least32_t score = INT_LEAST32_MIN;

	int_fast64_t pixelValue = INT_FAST64_MIN;

	printf("int32_t: %" PRId32 "\n",myInt32);

	printf("uint32_t: %" PRIu32 "\n", myUInt32);

	printf("uint64_t: %" PRIu64 "\n", myUInt64);

	return 0;
}