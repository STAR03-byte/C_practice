#include<iostream>
#include<stdio.h>

int main(void)
{
	printf("hello world!\n");
	printf("hello world!""\n");
	//printf("hello world!"'\n');
	std::cout << "hello world!" << '\n';
	std::cout << "hello world!" << "\n";

	return 0;
}

void apple()
{
	printf("apple\n");
}