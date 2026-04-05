#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main(void)
{
	const uint8_t total_laps = 10;//记录的是当前圈数终点的位置

	uint8_t current_laps = 0;//记录的是当前圈数终点的位置

	puts("开始跑步！");

	while (current_laps < total_laps)//与终点进行对比，比如在0圈的终点（第1圈的起点）完成的是第1圈，在第9圈的终点完成的是第10圈。
	{
		current_laps++;

		printf("跑步的人完成了第%"PRIu8"圈\n", current_laps);
	}

	return 0;
}

