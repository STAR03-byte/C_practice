#include "game_functions.h"

#include<stdio.h>
#include<string.h>
#include<errno.h>

void create_player(Player* player, const char* name, CharacterClass char_class) {
	errno_t err;
	err = strncpy_s(player->name, sizeof(player->name), name, _TRUNCATE);

	if (err!= 0) {
		printf("Error copying name: %d\n", err);
	}

	player->char_class = char_class;
	player->level = 1;
	player->health = 100;

	switch (char_class)
	{
	case Warrior:
		player->ablity.strength = 10; 
		break;
	case Mage:
		player->ablity.mana = 50;
		break;
	case Rogue:
		player->ablity.stealth = 20;
		break;
	}

}

Enemy generateEnemy(EnemyType type, int32_t level) {
	Enemy enemy;
	enemy.type = type;
	enemy.level = level;
	enemy.health = level * 20;

	switch (type)
	{
	case Goblin:enemy.ability.strength = 5 * level;
		break;
	case Troll:enemy.ability.strength = 10 * level;
		break;
	case Dragon:
		enemy.ability.mana = 100.0f * (float)level;
		break;
	}

	return enemy;
}

void battle(Player* player, Enemy* enemy) {
	printf("%s encounters a level %d %d ! A battle begins...\n", player->name, enemy->level, enemy->type);


	//all is win !!!

	player->exp += 50;
	printf("%s has defeated the enemy and gained 50 exp points!\n", player->name);
}

void print_player_info(const Player* player) {
	printf("Player Info : %s \n", player->name);
	printf("Class : %d,level: %d, Heath: %d\n", player->char_class, player->level, player->health);;

}

void parint_enemy_info(const Enemy* enemy) {
	printf("Enemy Info: Type %d, Level %d, Health %d", enemy->type, enemy->level, enemy->health);
}