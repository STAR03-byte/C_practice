#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char dest[20] = { 0 };

	strcpy_s(dest, sizeof(dest), "hello,");

	const char* src = "world\n";

	//最多追加的字符
	size_t max_cat = 7;

	errno_t result = strncat_s(dest, sizeof(dest), src, max_cat);

	if (result == 0) {
		printf("Concatenated string: %s\n", dest);
	}
	else {

		printf("Error!");
	}

	return 0;
}