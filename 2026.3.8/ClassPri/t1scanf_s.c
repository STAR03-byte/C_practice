#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	uint32_t age;

	int32_t result;

	result = scanf_s("%" SCNu32, &age);

	if (result == 1) {
		printf("You entered the integer: %" PRIu32, age);
	}
	else if(result == EOF){
		printf("An error occurred or end of file was reached.\n");
		return 1;
	}
	else {
		printf("Invalid input for integer.\n");
		return 1;
	}

	return 0;
}