#include "enemy_spawner.h"

#include "world.h"
#include "player.h"

EnemySpawner::EnemySpawner() {

}

EnemySpawner::~EnemySpawner() {
	for (Enemy* element : activeList) {
		delete element;
	}

	for (Enemy* element : inactiveList) {
		delete element;
	}
}

void EnemySpawner::Init(int x, int y, Player* target, int frameRate) {
	this->x = x;
	this->y = y;
	this->target = target;
	this->frameRate = frameRate;

	Enemy* enemy = new Enemy();
	enemy->parent = this;
	enemy->target = target;
	enemy->Init(frameRate);
	enemy->dead = false;

	inactiveList.push_back(enemy);
}

void EnemySpawner::Reset(Enemy* enemy) {
	enemy->dead = false;
	enemy->velocity = { 0, 0 };
	enemy->deltaX = 0;
	enemy->deltaY = 0;
	enemy->fade = 255;
	enemy->blueness = 255;
}

void EnemySpawner::Activate() {
	Enemy* enemy;

	if (!inactiveList.empty()) {
		enemy = inactiveList.back();
		inactiveList.pop_back();
	}
	else {
		enemy = new Enemy();
	}

	enemy->parent = this;
	enemy->target = target;

	enemy->Init(frameRate);
	Reset(enemy);

	activeList.push_back(enemy);
}

void EnemySpawner::Deactivate() {
	for (int i = 0; i < activeList.size(); ) {
		if (activeList[i]->dead) {
			Enemy* enemy = activeList[i];
			inactiveList.push_back(enemy);
			enemy->fade = 255;
			enemy->blueness = 255;
			activeList[i] = activeList.back();
			activeList.pop_back();
		}
		else {
			i++;
		}
	}
}

void EnemySpawner::Update() {
	for (Enemy* element : activeList) {
		element->Update();
	}

	Deactivate();
}

void EnemySpawner::Render(SDL_Renderer* renderer) {
	for (Enemy* element : activeList) {
		element->Render(renderer);
	}

	for (Enemy* element : inactiveList) {
		if (element->fade > 0 && element->dead) {
			element->Fade(renderer);
		}
	}
}