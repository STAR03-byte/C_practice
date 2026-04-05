#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main(void)
{
	const uint8_t PRICE = 5;

	uint8_t coin;

	uint8_t balance = 0;

	while (balance < PRICE)
	{
		puts("金额不够，请开始投币");

		scanf_s("%"PRIu8, &coin);

		if (coin == 1 || coin == 2 || coin == 5)
		{
			balance += coin;
			printf("当前的金额是%"PRIu8"元\n", balance);
		}
		else
		{
			printf("不支持该%"PRIu8"元的币种，请重新投币。\n", coin);
		}
	}
	
	if (balance > PRICE)
	{
		printf("这是找您的%"PRIu8"元零钱\n", balance - PRICE);
	}

	puts("谢谢惠顾，请取走饮料");

	return 0;
}