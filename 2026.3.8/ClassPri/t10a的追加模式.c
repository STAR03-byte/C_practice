#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void append_log_safe(const char* file_name, const char* msg);

int main(void)
{
	const char* log_file_name = "D:\\Users\\Star\\Desktop\\log.txt";

	const char* str = "select *from students";

	append_log_safe(log_file_name, str);


	return 0;
}

void append_log_safe(const char* file_name, const char* msg) {
	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, file_name, "a");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), err);

		fprintf(stderr, "Failed to open log file for appending: %s", error_msg);
		exit(EXIT_FAILURE);
	}

	fprintf(file_ptr, "%s\n", msg);

	fclose(file_ptr);
}