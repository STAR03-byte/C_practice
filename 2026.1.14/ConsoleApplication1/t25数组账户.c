#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

#define ACCOUNT_COUNT 3
int main()
{
	int64_t account_balance[ACCOUNT_COUNT] = { 10000,15000,20000 };

	int64_t total_assets = 0;

	puts("账户初始金额：");

	for (uint32_t i = 0; i < ACCOUNT_COUNT; i++)
	{
		printf("账户%" PRIu32 ":%" PRId64 "\n", i + 1, account_balance[i]);
	}

	puts("\n");

	account_balance[0] += 20000;
	account_balance[2] -= 1000;

	puts("账户变动后金额：");

	for (uint32_t i = 0; i < ACCOUNT_COUNT; i++)
	{
		total_assets += account_balance[i];

		printf("账户%" PRIu32 ":%" PRId64 "\n", i + 1, account_balance[i]);
	}

	printf("总资产: %" PRId64 "\n", total_assets);

	return 0;
}
