#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define ROCK 1
#define SCISSORS 2
#define PAPER 3

void print_instructions();
uint32_t get_player_move();
uint32_t get_computer_move();
void print_move(uint32_t move);
void determine_winner(uint32_t player_move, uint32_t computer_move);

int main(void)
{
	srand(time(NULL));

	print_instructions();

	//获取玩家和计算机的选择
	uint32_t player_move = get_player_move();

	uint32_t computer_move = get_computer_move();

	//展示玩家、计算机的选择
	puts("你选择了：");
	print_move(player_move);

	puts("计算机选择了：");
	print_move(computer_move);

	//判断结果进行展示
	determine_winner(player_move, computer_move);

	return 0;
}

void print_instructions()
{
	puts("石头，剪刀，布，游戏开始！");
	puts("规则：输入数字，确定猜拳。1石头，2剪刀，3布：");
	puts("====================================================");
}

uint32_t get_player_move()
{
	uint32_t move;
	puts("请选择1石头，2剪刀，3布：");
	scanf_s("%" SCNu32, &move);

	while (move<ROCK || move>PAPER)
	{
		puts("无效选择！请重新输入：1石头，2剪刀，3布");
		scanf_s("%" SCNu32, &move);
	}

	return move;
}

uint32_t get_computer_move()
{
	return (rand() % (PAPER - ROCK + 1)) + ROCK;
}

void print_move(uint32_t move)
{
	switch (move)
	{
	case ROCK:puts("石头"); break;
	case SCISSORS:puts("剪刀"); break;
	case PAPER:puts("布"); break;
	default:
		break;
	}
}

//void determine_winner(uint32_t player_move, uint32_t computer_move)
//{
//	if (computer_move == player_move)
//	{
//		puts("平局");
//	}
//	else if ((player_move == ROCK && computer_move == SCISSORS) || (player_move == SCISSORS && computer_move == PAPER) || (player_move == PAPER && computer_move == ROCK))
//	{
//		puts("你赢了");
//	}
//	else
//	{
//		puts("你输了");
//	}
//}

//牛逼大了frank!!!
void determine_winner(uint32_t player_move, uint32_t computer_move)
{
	if (computer_move == player_move)
	{
		puts("平局");
		return;
	}

	uint32_t winning_moves[4] = { 0,SCISSORS,PAPER,ROCK };

	if (computer_move == winning_moves[player_move])
	{
		puts("你赢了！");
	}
	else
	{
		puts("你输了！");
	}
}