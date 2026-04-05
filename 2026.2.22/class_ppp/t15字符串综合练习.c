#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<string.h>

#define TEXT_SIZE  100
#define WORD_SIZE  50
#define DELIMS   " ,.!?\n"

void replacedWord(const char* text, const char* oldWord, const char* newWord, char* result);
int countChar(const char* text, char ch);
int countWords(const char* text);
void extractUniqueWords(const char* text, char uinqueWords[][WORD_SIZE], int* uinqueCount);

int main(void)
{
	char text[TEXT_SIZE] = "This is a simple test. This text is for testing.";

	char replacedText[TEXT_SIZE] = { 0 };

	char oldWord[] = "test";

	char newWord[] = "example";

	char countCharTarget = 's';

	char uniqueWords[TEXT_SIZE][WORD_SIZE] = { 0 };

	int uinqueCount = 0;

	replacedWord(text, oldWord, newWord, replacedText);
	printf("Replaced Text : %s\n", replacedText);

	int charCount = countChar(replacedText, countCharTarget);
	printf("Character '%c' appear %d times.\n", countCharTarget, charCount);

	int wordCount = countWords(replacedText);
	printf("Total number of words: %d\n", wordCount);

	extractUniqueWords(replacedText, uniqueWords, &uinqueCount);
	puts("Unique words:");

	for (int i = 0; i < uinqueCount; i++)
	{
		printf("%s\n", uniqueWords[i]);
	}
	
	return 0;
}

void replacedWord(const char* text, const char* oldWord, const char* newWord, char* result) {
	char buffer[TEXT_SIZE] = { 0 };
	//指针，也可以用来存储字符串
	const char* pos = text;
	//中转的指针，同上
	const char* temp = text;
	size_t oldLen = strlen(oldWord);

	//用temp指向被替换的单词的头地址
	while ((temp = strstr(pos, oldWord))!= NULL) {
		//把将要被替换的单词前的字符串移植到buffer空字符串中
		strncat_s(buffer, sizeof(buffer), pos, temp - pos);
		//进行单词的替换
		strcat_s(buffer, sizeof(buffer), newWord);
		//将指针越过被替换的单词，用来找到后面的字符串
		pos = temp + oldLen;
	}

	//把被替换的单词后续的字符串拼接到buffer
	strcat_s(buffer, sizeof(buffer), pos);
	strcpy_s(result, TEXT_SIZE, buffer);
}

int countChar(const char* text, char ch) {
	int count = 0;
	while (*text) {
		if (*text == ch) {
			count++;
		}
		text++;
	}
	return count;
}

int countWords(const char* text) {
	int count = 0;
	char buffer[TEXT_SIZE] = { 0 };

	strcpy_s(buffer, TEXT_SIZE, text);

	char* context = NULL;

	char* token = strtok_s(buffer, DELIMS, &context);

	while (token != NULL) {
		count++;
		token = strtok_s(NULL, DELIMS, &context);
	}

	return count;
}

//提取出所有不重复的单词，并将这些唯一单词存储到二维字符数组中
void extractUniqueWords(const char* text, char uniqueWords[][WORD_SIZE], int* uniqueCount) {
	char tempText[TEXT_SIZE] = { 0 };
	strcpy_s(tempText, TEXT_SIZE, text);

	char* context = NULL;
	char* token = strtok_s(tempText, DELIMS, &context);

	while (token != NULL) {
		int found = 0;

		for (int  i = 0; i < *uniqueCount; ++i)
		{
			if (strcmp(token, uniqueWords[i]) == 0) {
				found = 1;
				break;
			}
		}

		if (!found) {
			strcpy_s(uniqueWords[*uniqueCount], WORD_SIZE, token);
			(*uniqueCount)++;
		}
		token = strtok_s(NULL, DELIMS, &context);
	}
	
}