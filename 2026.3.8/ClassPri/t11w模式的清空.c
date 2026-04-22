#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void clear_log_safe(const char* file_name);

int main(void)
{
	const char* file_name = "D:\\Users\\Star\\Desktop\\tesr_config.txt";


	clear_log_safe(file_name);


	return 0;
}

void clear_log_safe(const char* file_name) {
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, file_name, "w");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), err);

		fprintf(stderr, "Failed to open log file for appending: %s", error_msg);
		exit(EXIT_FAILURE);
	}

	fclose(file_ptr);
}