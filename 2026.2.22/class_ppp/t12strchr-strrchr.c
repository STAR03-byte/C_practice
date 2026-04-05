#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	const char* str = "heljlo,worrrwwwld!";

	char to_find = 'w';

	char* ptr_char = strchr(str, to_find);

	char* ptr_reverse_char = strrchr(str, to_find);

	if (ptr_char) {
		printf("找到了，%c的位置是%td\n", to_find, ptr_char - str + 1);
	}
	else {
		printf("没有找到!\n");
	}

	if (ptr_reverse_char) {
		printf("找到了，%c的位置是%td\n", to_find, ptr_reverse_char - str + 1);
	}
	else {
		printf("没有找到!\n");
	}

	return 0;

}