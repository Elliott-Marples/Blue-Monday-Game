#ifndef BLUE_MONDAY_ENEMY_SPAWNER_H_
#define BLUE_MONDAY_ENEMY_SPAWNER_H_

#include <vector>

#include "SDL.h"

#include "enemy.h"



class EnemySpawnerContainer;

class EnemySpawner {
public:
	EnemySpawner();
	~EnemySpawner();

	int x, y;
	int indexX, indexY;

	Player* target;
	int frameRate;

	std::vector<Enemy*> activeList;
	std::vector<Enemy*> inactiveList;
	EnemySpawnerContainer* parent;

	void Init(int x, int y, Player* target, int frameRate);
	void Reset(Enemy* enemy);
	void Activate();
	void Deactivate();
	void Update();
	void Render(SDL_Renderer* renderer);
};

#endif // !BLUE_MONDAY_ENEMY_SPAWNER_H_
