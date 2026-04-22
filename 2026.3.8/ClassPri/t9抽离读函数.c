#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void read_config_safe(const char* file_name);

int main(void)
{
	const char* file_name = "D:\\Users\\Star\\Desktop\\tesr_config.txt";

	read_config_safe(file_name);

	return 0;
}

void read_config_safe(const char* file_name) {
	FILE* file_ptr = NULL;

	char buffer[256];

	errno_t err = fopen_s(&file_ptr, file_name, "r");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), err);

		fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(buffer, sizeof(buffer), file_ptr)!= NULL) {
		printf("%s", buffer);
	}

	fclose(file_ptr);

}