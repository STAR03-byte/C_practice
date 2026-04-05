#include<stdio.h>
#include "game_structs.h"
#include "game_functions.h"

int main(void)
{
	puts("Welcome to the Text RPG Game!\n");

	Player player;
	create_player(&player, "STAR", Mage);

	print_player_info(&player);

	return 0;
}