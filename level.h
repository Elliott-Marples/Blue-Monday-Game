#ifndef BLUE_MONDAY_LEVEL_H_
#define BLUE_MONDAY_LEVEL_H_

#include "enemy_spawner_container.h"



class World;

class Level {
public:
	Level();

	int value;

	int frameRate;
	EnemySpawnerContainer* container;
	
	World* parent;

	void Init();
	void Increment();
	void LevelUp();
};

#endif // !BLUE_MONDAY_LEVEL_H_
