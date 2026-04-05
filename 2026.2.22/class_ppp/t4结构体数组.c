#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

typedef struct {
	int32_t x;
	int32_t y;
}Point;

int main(void)
{
	Point points[2] = {
		{1,2},{3,4}
	};

	for (size_t i = 0; i < 2; i++)
	{
		printf("point%zu: (%" PRId32 ",%" PRId32 ")\n", i, points[i].x, points[i].y);
	}

	return 0;
}