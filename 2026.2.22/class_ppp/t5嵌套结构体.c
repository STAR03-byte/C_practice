#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>

typedef struct {
	char street[50];
	char city[50];
	char country[50];
}Address;

typedef struct {
	char name[50];
	uint16_t age;
	Address address;//Ç¶Ì×½á¹¹Ìå
}Person;

int main(void)
{
	Person star = { "star",79,{"shangshui","henan","China"} };

	printf("Address:%s,%s,%s\n", star.address.country, star.address.city, star.address.street);

	Person* ptr_star = &star;

	printf("Address:%s,%s,%s\n", ptr_star->address.country, ptr_star->address.city, ptr_star->address.street);

	return 0;
}