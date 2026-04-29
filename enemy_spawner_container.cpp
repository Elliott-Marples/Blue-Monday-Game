#include "enemy_spawner_container.h"

#include "world.h"

EnemySpawnerContainer::EnemySpawnerContainer() {

}

EnemySpawnerContainer::~EnemySpawnerContainer() {
	for (EnemySpawner* element : spawnerList) {
		delete element;
		SDL_Log("Deleted spawner\n");
	}
}

void EnemySpawnerContainer::Init(int frameRate) {
	// Spawner Timer
	spawnRate = frameRate * 4;
	spawnTimer = spawnRate;
	spawnNum = 1;

	// Spawner Pattern
	spawnersX = 5;
	spawnersY = 3;

	this->enemySpeed = 5;

	this->frameRate = frameRate;

	int spacing = 25;
	int deltaX = (parent->maxBoundX + spacing * 2) / spawnersX;
	int deltaY = (parent->maxBoundY + spacing * 2) / spawnersY;

	// Top & Bottom rows
	for (int x = 0; x < spawnersX; x++) {
		EnemySpawner* top = new EnemySpawner;
		EnemySpawner* bottom = new EnemySpawner;

		top->parent = this;
		bottom->parent = this;

		top->Init(-spacing + deltaX * x, -spacing, &parent->player, frameRate);
		bottom->Init(-spacing + deltaX * x, parent->maxBoundY + spacing, &parent->player, frameRate);

		spawnerGrid[x][0] = top;
		spawnerGrid[x][spawnersY - 1] = bottom;

		spawnerList.push_back(top);
		spawnerList.push_back(bottom);
	}

	// Left & Right columns
	for (int y = 1; y < spawnersY - 1; y++) {
		EnemySpawner* left = new EnemySpawner;
		EnemySpawner* right = new EnemySpawner;

		left->parent = this;
		right->parent = this;

		left->Init(-spacing, -spacing + deltaY * y, &parent->player, frameRate);
		right->Init(parent->maxBoundX + spacing, -spacing + deltaY * y, &parent->player, frameRate);

		spawnerGrid[0][y] = left;
		spawnerGrid[spawnersX - 1][y] = right;

		spawnerList.push_back(left);
		spawnerList.push_back(right);
	}

	// Spawner List
	for (EnemySpawner* element : spawnerList) {
		SDL_Log("Spawner [%i,%i] - X: %i, Y: %i\n", element->indexX, element->indexY, element->x, element->y);
	}
}

void EnemySpawnerContainer::Update() {
	for (EnemySpawner* element : spawnerList) {
		element->Update();
	}

	// Spawns enemies at random spawners
	spawnTimer--;
	//SDL_Log("Timer:%i\n", spawnTimer);

	if (spawnTimer <= 0) {
		for (int i = 0; i < spawnNum; i++) {
			int spawnSide = rand() % 4;
			switch (spawnSide) {
			case 0:
				randomSpawnX = rand() % spawnersX;
				randomSpawnY = 0;
				break;

			case 1:
				randomSpawnX = spawnersX - 1;
				randomSpawnY = rand() % spawnersY;
				break;

			case 2:
				randomSpawnX = rand() % spawnersX;
				randomSpawnY = spawnersY - 1;
				break;

			case 3:
				randomSpawnX = 0;
				randomSpawnY = rand() % spawnersY;
				break;
			}

			spawnerGrid[randomSpawnX][randomSpawnY]->Activate();
		}
		spawnTimer = spawnRate;
	}
}

void EnemySpawnerContainer::Render(SDL_Renderer* renderer) {
	for (EnemySpawner* element : spawnerList) {
		element->Render(renderer);
	}
}