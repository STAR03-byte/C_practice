#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, "D:\\Users\\Star\\Desktop\\tesr.txt", "w");

	if (err != 0 || file_ptr == NULL) {
		perror("Failed to open file");
		return EXIT_FAILURE;
	}

	fputc('h', file_ptr);
	fputc('i', file_ptr);
	fputc('\n', file_ptr);

	fputs("This is a example!\n", file_ptr);

	float pi = 3.14;

	fprintf_s(file_ptr, "number: %d,%f,%s\n", 10, pi, "End of example.");

	fclose(file_ptr);

	puts("file has been written successfully!\n");

	return 0;
}