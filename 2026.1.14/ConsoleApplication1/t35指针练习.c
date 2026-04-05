#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main(void)
{
	//指针的算数运算

	uint32_t numbers[] = { 10,20,30,40,50,60,70,80,90,100 };

	uint32_t* ptr = numbers;

	uint32_t size = sizeof(numbers) / sizeof(numbers[0]);

	printf("size = %" PRIu32 "\n", size);

	printf(" 数组原始数据\nnumbers[] = { ");
	for (uint32_t i = 0; i < size; i++)
	{
		printf("%" PRIu32 " ", numbers[i]);
	}
	printf("}\n\n");

	//使用指针加法移动指针
	printf("使用指针加法访问第5个元素: \n");

	ptr += 4;

	printf("number[ptr += 4] : %" PRIu32 "\n\n", *ptr);

	//使用指针减法回到第一个元素
	ptr -= 4;

	printf("number[ptr -= 4] : %" PRIu32 "\n\n", *ptr);

	//指针之间的减法计算距离
	uint32_t* start_ptr = &numbers[0];
	uint32_t* end_ptr = &numbers[size - 1];

	printf("数组首尾之间的距离是: %" PRId64 "\n\n", end_ptr - start_ptr);

	//指针之间的比较

	puts("比较指针指向的元素: ");
	if (start_ptr < end_ptr)
	{
		puts("start_ptr 指向的元素在 end_ptr 所指向的元素之前");
	}

	//使用指针遍历数组
	printf("使用指针遍历数组\n外部指针遍历*p = { ");

	for (uint32_t* p = start_ptr; p <= end_ptr; ++p)
	{
		printf("%" PRIu32 " ", *p);
	}
	printf("}\n\n");

	//使用指针减法逐个访问素组中的每个元素的反向顺序
	printf("使用指针减法逐个访问素组中的每个元素的反向顺序\n*p = { ");

	for (uint32_t* p = end_ptr; p >= start_ptr; p--)
	{
		printf("%" PRIu32 " ", *p);
	}
	printf("}\n\n");

	//指针加减整数访问特定元素
	puts("指针加减整数访问特定元素:");

	int offset = 3;

	printf("第四个元素 (使用加法) :*(start_ptr + offset) = %" PRIu32 "\n\n", *(start_ptr + offset));

	//回退到第三个元素
	printf("回退到第三个元素(从第四个元素开始回退）*(start_ptr + offset - 1) = %" PRIu32 "\n\n", *(start_ptr + offset - 1));

	//比较两个指针

	uint32_t* middle_ptr = &numbers[size / 2];

	printf("比较两个指针指向的位置:\n");

	if (start_ptr < middle_ptr)
	{
		puts("start_ptr 指向的元素在 middle_ptr 所指向的元素之前");
	}

	if (end_ptr > middle_ptr)
	{
		puts("end_ptr 指向的元素在 middle_ptr 所指向的元素之后");
	}
	return 0;
}