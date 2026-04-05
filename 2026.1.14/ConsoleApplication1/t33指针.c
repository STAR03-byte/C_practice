#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<stdlib.h>

int main(void)
{
	int building_floors[5] = { 101,102,103,104,105 };

	int target_floor = 102;

	int *ptr_floor_102 = &building_floors[1];

	printf("%p\n", &building_floors[1]);

	printf("%p\n", ptr_floor_102);

	int* ptr_new_106 = ptr_floor_102;

	*ptr_new_106 = 106;

	printf("%p\n", ptr_new_106);

	printf("%d\n", building_floors[1]);

	return 0;
}