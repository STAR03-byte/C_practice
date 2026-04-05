#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

int main(void)
{
	//strstr

	const char* text = "This is a simple test simple string !";

	const char* sub = "simple";

	char* result = strstr(text, sub);

	if (result != NULL) {
		printf("Found '%s' in \"%s\" at position: %td\n", sub, text, result - text + 1);
	}
	else {
		printf("Sustring '%s' not found in \"%s\".\n", sub, text);
	}

	return 0;
}