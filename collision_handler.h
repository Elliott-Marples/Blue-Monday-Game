#ifndef BLUE_MONDAY_COLLISION_HANDLER_H_
#define BLUE_MONDAY_COLLISION_HANDLER_H_

#include <algorithm>

#include "SDL.h"

#include "enemy_spawner_container.h"
#include "player.h"
#include "bullet_container.h"



class World;

class CollisionHandler {
public:
	CollisionHandler();

	EnemySpawnerContainer* spawners;
	Player* player;
	BulletContainer* bulletContainer;

	World* parent;

	void Init(int frameRate, EnemySpawnerContainer* spawners, Player* player);
	void Update();
	bool CheckCollisions(SDL_Rect* bodyA, SDL_Rect* bodyB);
	void ResolveCollision(SDL_Rect* bodyA, SDL_Rect* bodyB);
	void ResolveEnemyCollisions(EnemySpawnerContainer* spawners, Player* player);
	void ResolveBulletCollisions(BulletContainer* bulletContainer, EnemySpawnerContainer* spawners);
};

#endif // !BLUE_MONDAY_COLLISION_HANDLER_H_
