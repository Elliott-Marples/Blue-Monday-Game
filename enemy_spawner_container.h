#ifndef BLUE_MONDAY_ENEMY_SPAWNER_CONTAINER_H_
#define BLUE_MONDAY_ENEMY_SPAWNER_CONTAINER_H_

#include "enemy_spawner.h"

#define MAX_X = 5
#define MAX_Y = 3



class World;

class EnemySpawnerContainer {
private:
	int spawnersX = 5;
	int spawnersY = 3;
	int spawnTimer;
	int randomSpawnX, randomSpawnY;

public:
	EnemySpawnerContainer();
	~EnemySpawnerContainer();


	std::vector<EnemySpawner*> spawnerList;
	EnemySpawner* spawnerGrid[5][3];

	int enemySpeed;
	int spawnRate;
	int spawnNum;
	int frameRate;
	World* parent;

	void Init(int frameRate);
	void Update();
	void Render(SDL_Renderer* renderer);
};

#endif // !BLUE_MONDAY_ENEMY_SPAWNER_CONTAINER_H_
