#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char str[] = "This is a sample string!";

	char delim[] = " ";

	char* token;

	char* context = { 0 };	//保存strtok_s函数在其内部位置之间的上下文指针

	token = strtok_s(str, delim, &context);

	while (token != NULL) {
		printf("Token : %s\n", token);
		token = strtok_s(NULL, delim, &context);
	}

	return 0;
}