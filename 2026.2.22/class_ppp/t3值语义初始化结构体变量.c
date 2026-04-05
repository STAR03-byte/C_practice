#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

typedef struct {
	int16_t x;
	int16_t y;
}Point;

Point get_point(void);

int main(void)
{
	Point zhangsan = get_point();

	printf("(%" PRId16 ",%" PRId16 ")\n", zhangsan.x, zhangsan.y);

	return 0;
}

Point get_point(void) {
	//值语义
	Point p = { 10,20 };
	return p;//return一个结构体副本
}

