#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	const char* str1 = "hello,world\n";

	const char* str2 = "hello,world\n";

	const char* str3 = "hello,guys\n";

	size_t num = 6;

	if (strncmp(str1, str3, num) == 0) {
		printf("Str1 and Str3 are equal!\n");
	}
	else {
		printf("Str1 and Str3 are not equal!\n");
	}

	return 0;
}