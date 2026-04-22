#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>

void read_config_safe(const char* filename);

int main(void)
{
	const char* filename = "D:\\Users\\Star\\Desktop\\tesr.txt";

	read_config_safe(filename);

	return 0;
}

void read_config_safe(const char* filename) {
	FILE* file_ptr = NULL;
	errno_t err = fopen_s(&file_ptr, filename, "r");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), errno);

		fprintf(stderr, "Failed to open file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[256];
	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("%s", buffer);
	}

	fclose(file_ptr);
}