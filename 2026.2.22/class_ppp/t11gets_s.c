#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	char buffer[20];

	gets_s(buffer, sizeof(buffer));

	printf("result : %s", buffer);

	return 0;
}