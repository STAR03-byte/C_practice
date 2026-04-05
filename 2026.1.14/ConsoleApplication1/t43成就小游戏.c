#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

#define MAX_ACHIEVEMENTS 10

const char* achievements[MAX_ACHIEVEMENTS];

size_t achievement_count = 0;

void add_achievement(const char* new_achievement);

void print_achievements();

int main(void)
{
	add_achievement("成就一");

	add_achievement("成就二");

	print_achievements();

	return 0;
}

void add_achievement(const char* new_achievement) {
	if (achievement_count < MAX_ACHIEVEMENTS) {
		//这里使用 achievement_count++ 是为了先赋值，再计数，保证数组使用的连续性和计数器的准确性。
		achievements[achievement_count++] = new_achievement;
	}
	else {
		printf("成就已满，无法添加\n");
	}
}

void print_achievements() {
	printf("玩家成就列表：\n");
	for (size_t i = 0; i < achievement_count; i++)
	{
		printf("%zu: %s\n", i + 1, achievements[i]);
	}
}