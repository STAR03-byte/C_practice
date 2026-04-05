#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main() {

	uint32_t num1 = 25;

	printf("Orignial number £º%"PRIu32"\n", num1);

	uint32_t result = num1 << 10;

	printf("Result: %"PRIu32"\n", result);


	return 0;
}