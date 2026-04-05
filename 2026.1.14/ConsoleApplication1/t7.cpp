#include<stdio.h>
#include<stdint.h>

int main() {

	uint32_t a = 1, b = 2, c = 3;

	uint32_t result = (a += 1, b += 2, c += 3);

	printf("a += 1 = %d , b += 2 = %d , c += 3 = %d \nresult = %d", a, b, c, result);

	return 0;
}