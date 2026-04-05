#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	FILE* file_str;

	errno_t err = fopen_s(&file_str, "D:\\Users\\Star\\Desktop\\tesr.txt", "r");

	if (err != 0 || file_str == NULL) {
		perror("无法打开文件!");
		return EXIT_FAILURE;
	}

	char buffer[100];

	while (fgets(buffer, sizeof(buffer), file_str) != NULL) {
		printf("%s\n", buffer);
	}

	if (ferror(file_str)) {
		perror("文件读取错误");
		clearerr(file_str);
	}

	if (feof(file_str)) {
		printf("已经到达了文件的末尾\n");
	}
	else {
		printf("未达到文件的末尾,可能因为发生了错误\n");
	}


	fclose(file_str);

	return 0;
}