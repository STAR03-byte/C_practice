#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	uint32_t secret_num, guess;

	srand(time(NULL));

	secret_num = rand() % 100 + 1;

	//while (true)
	//{
	//	puts("输入你猜的数字：");

	//	scanf_s("%" PRIu32, &guess);

	//	if (guess < secret_num)
	//	{
	//		puts("太小了");
	//	}
	//	else if (guess > secret_num)
	//	{
	//		puts("太大了");
	//	}
	//	else
	//	{
	//		puts("猜对了");
	//		break;
	//	}

	//}
	do {
		puts("输入你猜的数字：");

		scanf_s("%" PRIu32, &guess);

		if (guess < secret_num)
		{
			puts("太小了");
		}
		else if (guess > secret_num)
		{
			puts("太大了");
		}

	} while (guess != secret_num);

	puts("猜对了");

	return 0;
}