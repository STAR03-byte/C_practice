#include<stdio.h>
#include<stdint.h>
//#include<stdbool.h>
#include<inttypes.h>

int main() {
	
	uint8_t num1 = 45;
	int8_t num2 = -17;

	uint16_t sum = num1 + num2;
	int16_t diff = num2 - num1;

	printf("The result of sum : %" PRIu16 "\n", sum);
	printf("The result of diff : %" PRId16 "\n", diff);

	uint32_t myUint32 = UINT32_MAX;
	int32_t myInt32 = INT32_MIN;

	printf("My Uint32 : %" PRIu32 "\n", myUint32);
	printf("My Int32 : %" PRId32 "\n", myInt32);

	uint_fast64_t fast_num = UINT_FAST16_MAX;
	int_least64_t least_num = INT_LEAST32_MAX;

	printf("Fast64 : %" PRIu64 "\n", fast_num);
	printf("Least64 : %" PRId64"\n", least_num);

	//printf("Fast64 : %" PRIuFAST64 "\n", fast_num);
	//printf("Least64 : %" PRIdLEAST64"\n", least_num);

	float numf = 1.0f / 3.9f;

	printf("FloatNum : %f\n", numf);

	double numd = 1.0 / 3.9;

	printf("DoubleNum : %lf\n", numd);

	long double numLD = 4545.797370L;

	printf("LD_Num : %llf\n", numLD);

	char myChar = 'd';

	printf("MyChar : %c\n", myChar);

	bool girl = true;

	printf("\a\t\t\t\\\n");

	printf("\033[2J");

	return 0;
}