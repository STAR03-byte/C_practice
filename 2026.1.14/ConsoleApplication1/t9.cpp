#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

int main()
{
	uint8_t traffic_light_state = 0;

	switch (traffic_light_state)
	{
	case 0:
		puts("Red");
		traffic_light_state = 1;
		break;
	case 1:
		puts("Green");
		traffic_light_state = 2;
		break;
	case 2:
		puts("Yellow");
		traffic_light_state = 0;
		break;
	default:
		puts("???");
		break;
	}

	printf("now state : %" PRIu8 "\n", traffic_light_state);

	return 0;
}