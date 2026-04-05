#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

void check_wrong_attempts(uint8_t);

int main()
{
	//uint8_t wrong_attempts{};

	check_wrong_attempts(5);

}

void check_wrong_attempts(uint8_t wrong_attempts)
{
	bool is_locked = wrong_attempts >= 3;

	if (is_locked)
	{
		puts("您的账户已被锁定！！！");

	}

}
