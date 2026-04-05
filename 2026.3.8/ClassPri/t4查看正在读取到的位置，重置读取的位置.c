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

	errno_t err = fopen_s(&file_ptr, "D:\\Users\\Star\\Desktop\\tesr.txt", "r+");

	if (err != 0 || file_ptr == NULL) {
		perror("无法打开文件！");
		return EXIT_FAILURE;
	}

	long position = ftell(file_ptr);
	printf("当前文件的位置:%ld\n", position);

	char buffer[100];

	//fget函数，读取一行
	if (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
		printf("从文件读取: %s", buffer);
		//查看最新的位置
		position = ftell(file_ptr);
 		printf("现在的位置: %ld\n", position);
	}

	//使用fseek函数移动到文件的开始
	fseek(file_ptr, 0, SEEK_SET);
	printf("使用fseek函数移动到的新位置，SEEK_SET = 0: %ld\n", ftell(file_ptr));

	//适用rewind直接移动到开始的位置
	rewind(file_ptr);
	printf("使用rewind函数移动到的新位置: %ld\n", ftell(file_ptr));

	fclose(file_ptr);


	return 0;
}