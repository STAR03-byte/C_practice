#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	FILE* stream;

	errno_t err = fopen_s(&stream, "D:\\Users\\Star\\Desktop\\tesr.txt", "w+");

	if (err != 0) {
		printf_s("文件无法打开\n");
		return EXIT_FAILURE;
	}

	int id = 1;
	float temperature = 36.5f;
	char name[] = "Frank";
	char grade = 'A';

	fprintf(stream, "ID:%dn\n", id);
	fprintf(stream, "name:%s\n", name);
	fprintf(stream, "Temperature:%.1f\n", temperature);
	fprintf(stream, "Grade:%c", grade);


	fclose(stream);

	puts("文件写入完成\n");

	return 0;
}