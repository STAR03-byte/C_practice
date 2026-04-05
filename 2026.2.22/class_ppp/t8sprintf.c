#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>


int main(void)
{
	char buffer[50] = { 0 };

	int number1 = 7;

	double pi = 3.1415926;

	//格式化输出
	int ret  = sprintf_s(buffer, sizeof(buffer), "Integer : %d ,Double : %.2f", number1, pi);

	if (ret > 0) {
		printf("Formatted string : %s", buffer);
	}
	else {
		printf("Error!");
	}

	return 0;
}