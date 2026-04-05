#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<ctype.h>

#define LETTER_COUNT 26
int main()
{
	uint32_t frequency[LETTER_COUNT] = { 0 };

	char text[] = "Example text for frequency analysis.";

	for (uint8_t i = 0; text[i] != '\0'; i++)
	{
		char ch = tolower(text[i]);

		if (ch >= 'a' && ch <= 'z')
		{
			frequency[ch - 'a']++;
		}
	}

	puts("字母频率：");

	for (uint8_t i = 0; i < LETTER_COUNT; i++)
	{
		if (frequency[i] > 0) {
			printf("%c:的频率为:%" PRIu32 "\n", 'a' + i, frequency[i]);
		}
	}

	return 0;
}