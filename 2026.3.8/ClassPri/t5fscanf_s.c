#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>
#include<errno.h>

int main(void)
{
	FILE* stream;

	long l;
	float fp;
	char s[81];
	char c;

	errno_t err = fopen_s(&stream, "D:\\Users\\Star\\Desktop\\tesr.txt", "r");

	if (err) {
		printf_s("This file was not opened!");
	}
	else {
		if (fscanf_s(stream, "%80s", s, (unsigned)_countof(s)) != 1) {
			printf("∂¡»°◊÷∑˚¥Æ ß∞‹!\n");
		}

		if (fscanf_s(stream, "%lds", &l) != 1) {
			printf("∂¡»°ld ß∞‹!\n");
		}

		if (fscanf_s(stream, "%f", &fp) != 1) {
			printf("∂¡»°lf ß∞‹!\n");
		}
		
		if (fscanf_s(stream, " %c", &c,1) != 1) {
			printf("∂¡»°c ß∞‹!\n");
		}

		printf("%s\n", s);

		printf("%ld\n", l);

		printf("%lf\n", fp);

		printf("%c\n", c);

		fclose(stream);
	}
	return 0;
}