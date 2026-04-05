#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	//strspn

	const char* str1 = "123456jijjiji90";

	const char* str2 = "12345jijijiji90";

	size_t len1 = strspn(str1, str2);

	printf("%zu\n", len1);

	//strcspn

	const char* str3 = "hello,world!";

	const char* str4 = ",";

	size_t len2 = strcspn(str3, str4);

	printf("%zu\n", len2);

	char input[] = "fil\\ename.txt";

	const char* invalid_chars = "/\\:*?\"<>|";

	if (strcspn(input, invalid_chars) < strlen(input)) {
		puts("Input contains invalid characters!");
	}
	else {
		puts("Input is valid!");
	}

	return 0;
}