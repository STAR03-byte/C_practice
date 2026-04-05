#include<stdio.h>
#include<stdint.h>

int main(void)
{
	int16_t myInt16 = 32767;
	uint16_t myUInt16 = UINT16_MAX;

	int32_t myInt32 = INT32_MIN;
	uint32_t myUInt32 = 4294967295U;

	int64_t myInt64 = 9223372036854775807LL;
	uint64_t myUInt64 = 18446744073709551615ULL;

	printf("Size of int16_t: %zu byte(s)\n", sizeof(myInt16));

	printf("Size of uint16_t: %zu byte(s)\n", sizeof(myUInt16));

	printf("Size of int32_t: %zu byte(s)\n", sizeof(myInt32));

	printf("Size of uint32_t: %zu byte(s)\n", sizeof(myUInt32));

	printf("Size of int64_t: %zu byte(s)\n", sizeof(myInt64));

	printf("Size of uint64_t: %zu byte(s)\n", sizeof(myUInt64));

	return 0;
}