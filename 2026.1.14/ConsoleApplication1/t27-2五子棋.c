#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<wchar.h>
#include<locale.h>
#include<Windows.h>
#include<stdbool.h>

#define board_size 15

int main(void)
{
	//functions 一个工具
	//设置控制台代码为 UTF-8
	SetConsoleOutputCP(65001);

	//设置区域为当前系统默认区域
	setlocale(LC_ALL, "");

	wchar_t board[board_size][board_size];
	uint8_t x, y;

	//状态

	wchar_t current_play = 0x25CF;
	//初始化棋盘
	for (uint32_t i = 0; i < board_size; i++)
	{
		for (uint32_t j = 0; j < board_size; j++)
		{
			board[i][j] = 0x00B7;
		}
	}

	wchar_t control = L'y';
	while (control == L'y' || control == L'Y')
	{
		system("cls");//清屏
		for (uint32_t i = 0; i < board_size; i++)
		{
			for (uint32_t j = 0; j < board_size; j++)
			{
				wprintf(L"%lc  ", board[i][j]);
			}
			puts("\n");
		}
		while (true)
		{
			printf("玩家 %lc 请输入坐标 (0 - %d),中间用空格隔开:\n", current_play, board_size - 1);
			if (scanf_s("%" SCNu8 "%" SCNu8, &x, &y) != 2)
			{
				while (getchar() != '\n');
				puts("输入无效，请重新输入。\n");
				continue;
			}

			if (x < board_size && y < board_size && board[x][y] == 0x00B7)
			{
				board[x][y] = current_play;
				current_play = (current_play == 0X25CF) ? 0x25CB : 0x25CF;
				break;
			}
			else
			{
				puts("无效的移动，请重试！\n");
				while (getchar() != '\n'); //清空输入缓冲区
			}
		}

		system("cls");
		for (uint32_t i = 0; i < board_size; i++)
		{
			for (uint32_t j = 0; j < board_size; j++)
			{
				wprintf(L"%lc  ", board[i][j]);
			}
			puts("\n");
		}

		printf("是否继续？(y / n):\n");
		while (getchar() != '\n');
		wscanf_s(L" %lc", &control, 1);
	}
	puts("游戏结束！\n");

	return 0;
}