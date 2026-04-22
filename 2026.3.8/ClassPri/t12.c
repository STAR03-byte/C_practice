#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define BUFFER_SIZE 1024

errno_t update_log_record(const char* file_name, const char* search_str, const char* replace_str);

int main(void)
{
	const char* log_file = "D:\\Users\\Star\\Desktop\\log.txt";

	const char* search_str = "INFO:     127.0.0.1:4296 - GET / api / v1 / auth / me HTTP / 1.1 200 OK";

	const char* replace_str = "you are ringht!";

	errno_t result = update_log_record(log_file, search_str, replace_str);

	_fcloseall();

	return 0;
}

errno_t update_log_record(const char* file_name, const char* search_str, const char* replace_str) 
{
	if (file_name == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL;	//返回无效参数错误
	}

	FILE* file_ptr = NULL;

	errno_t err = fopen_s(&file_ptr, file_name, "r+");

	if (err != 0 || file_ptr == NULL) {
		char error_msg[256];

		strerror_s(error_msg, sizeof(error_msg), err);

		fprintf(stderr, "Failed to open log file for updating: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	long position = 0;
	int found = 0;

	while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) 
	{
		if (strstr(buffer, search_str) != NULL) 
		{
			found = 1;
			position = ftell(file_ptr) - (long)strlen(buffer) - 1;
			break;
		}
	}

	if (found)
	{
		fseek(file_ptr,position,SEEK_SET)	//移动到找到的位置

	}
}