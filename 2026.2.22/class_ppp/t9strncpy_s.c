#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main()
{
	char dest[50] = { 0 };

	const char* src = "hello,world\n";

	size_t max_copy = 10;

	errno_t result = strncpy_s(dest, sizeof(dest), src, max_copy);

	if (result == 0) {
		printf("Copied string : %s\n", dest);
	}
	else {
		printf("Error copying string!\n");
	}

	return 0;
}