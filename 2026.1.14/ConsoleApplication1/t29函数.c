#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define PI 3.1415926

double square_area(double side);
double rectangle_area(double length, double width);
double circle_area(double redius);
bool is_leap_year(uint32_t year);

int main(void)
{
	//double area_sq = square_area(5);

	//printf("正方形的面积是：%.2f\n", area_sq);

	//printf("矩形的面积是：%.2f\n", rectangle_area(5.6, 32.6));

	//printf("圆形的面积是：%f\n", circle_area(6.3));

	uint32_t year;

	puts("请输入年份：");

	scanf_s("%" SCNu32, &year);

	printf("%" PRIu32 "年%s", year, is_leap_year(year) ? "是闰年" : "不是闰年");

	return 0;
}

double square_area(double side)
{
	return side * side;
}

double rectangle_area(double length, double width)
{
	return length * width;
}

double circle_area(double redius)
{
	return PI * redius * redius;
}

bool is_leap_year(uint32_t year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}