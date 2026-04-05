#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>

#define EXP_PEP_LEVEL 100
#define	MAX_LEVEL 10
#define HINTS_COUNT 10

void increase_exp(int32_t* exp, int32_t amout);
bool check_level_up(int32_t* exp, int32_t* level);
const char* get_treasure_hint(int32_t level);

int main(void)
{
	/*
		游戏概念。

		玩家属性：exp，level.

		解密：

		等级提升：

		游戏的目标：
	*/

	int32_t play_exp = 0;

	int32_t play_level = 1;

	//模拟玩家解密获得经验值
	increase_exp(&play_exp, 100);
	
	increase_exp(&play_exp, 200);

	if (check_level_up(&play_exp, &play_level))
	{
		printf("%s\n", get_treasure_hint(play_level));
	}
	else
	{
		printf("还需要更多经验才能升级!");
	}

	return 0;
}

void increase_exp(int32_t* exp, int32_t amount)
{
	*exp += amount;
}

bool check_level_up(int32_t* exp, int32_t* level)
{	
	bool level_flag = false;

	while (*exp >= EXP_PEP_LEVEL && *level < MAX_LEVEL)
	{
		level_flag = true;
		*exp -= EXP_PEP_LEVEL;
		(*level)++;
	}
	printf("恭喜你升到了%" PRIu32 "级!\n", *level);
	if (level_flag)
	{
		return true;
	}

	return false;
}

const char* get_treasure_hint(int32_t level)
{
	static const char* hints[HINTS_COUNT] = {
		"提示一：········",
		"提示二：·········",
		"tips3",
		"tips4"
	};
	
	if (level > 0 && (size_t)level <= HINTS_COUNT)
	{
		return hints[(size_t)level - 1];
	}

	return "确保在等级的有效范围之内";
}