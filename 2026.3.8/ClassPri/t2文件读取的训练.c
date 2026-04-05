#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	FILE* file_stream = NULL;

	char buffer[256];

	//打开文件，设定文件的操作模式为R(读）
	errno_t err = fopen_s(&file_stream, "D:\\Users\\Star\\Desktop\\tesr.txt", "r");

	if (err != 0 || file_stream == NULL) {
		perror("Error open file");
		return EXIT_FAILURE;
	}

	while (fgets(buffer, sizeof(buffer), file_stream) != NULL) {
		printf("缓冲区文件：%s", buffer);
	}

	//此时file_stream指针已经停滞了

	memset(buffer, 0, sizeof(buffer));

	rewind(file_stream);

	int ch;

	while ((ch = fgetc(file_stream)) != EOF) {
		putchar(ch);
	}
	
	if (fclose(file_stream) != 0) {
		perror("Error close file");
		return EXIT_FAILURE;
	}

	

	return 0;

}