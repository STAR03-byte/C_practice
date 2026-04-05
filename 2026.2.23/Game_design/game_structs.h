#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include "game_abilities.h"
#include "game_types.h"

typedef struct {
	char name[50];
	CharacterClass char_class;
	Ability ablity;
	int32_t level;
	int32_t health;
	int32_t exp;
}Player;		//玩家属性

typedef struct {
	EnemyType type;
	Ability ability;
	int32_t level;
	int32_t health;
}Enemy;			//怪物属性

typedef struct {
	char name[50];
	ItemType type;
	int32_t power;
}Item;			//道具属性

#endif // !GAME_STRUCTS_H

