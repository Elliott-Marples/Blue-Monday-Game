#include "collision_handler.h"

#include "world.h"

CollisionHandler::CollisionHandler() {

}

void CollisionHandler::Init(int frameRate, EnemySpawnerContainer* spawners, Player* player) {
	this->spawners = spawners;
	this->player = player;
	this->bulletContainer = &player->bulletContainer;
}

void CollisionHandler::Update() {
	ResolveEnemyCollisions(spawners, player);
	ResolveBulletCollisions(bulletContainer, spawners);
}

bool CollisionHandler::CheckCollisions(SDL_Rect* bodyA, SDL_Rect* bodyB) {
	bool overlapX = (bodyA->x < bodyB->x + bodyB->w) &&
					(bodyA->x + bodyA->w > bodyB->x);
	bool overlapY = (bodyA->y < bodyB->y + bodyB->h) &&
					(bodyA->y + bodyA->w > bodyB->y);
	bool isColliding = overlapX && overlapY;

	return isColliding;
}

void CollisionHandler::ResolveCollision(SDL_Rect* bodyA, SDL_Rect* bodyB) {
	// Find overlapping region on X axis
	int left = std::max(bodyA->x, bodyB->x);
	int right = std::min(bodyA->x + bodyA->w, bodyB->x + bodyB->w);
	int overlapX = right - left;

	// Find overlapping region on Y axis
	int top = std::max(bodyA->y, bodyB->y);
	int bottom = std::min(bodyA->y + bodyA->h, bodyB->y + bodyB->h);
	int overlapY = bottom - top;

	// Exit if no overlap
	if (overlapX <= 0 || overlapY <= 0) return;

	// Find center points
	float centerA_X = bodyA->x + bodyA->w / 2;
	float centerB_X = bodyB->x + bodyB->w / 2;
	float centerA_Y = bodyA->y + bodyA->h / 2;
	float centerB_Y = bodyB->y + bodyB->h / 2;

	// Resolve smallest overlapping axis
	if (overlapX < overlapY) {
		// Move A left out of B
		if (centerA_X < centerB_X) {
			bodyA->x -= overlapX;
		}
		// Move A right out of B
		else {
			bodyA->x += overlapX;
		}
	}
	else {
		// Move A up out of B
		if (centerA_Y < centerB_Y) {
			bodyA->y -= overlapY;
		}
		// Move A down out of B
		else {
			bodyA->y += overlapY;
		}
	}
}

void CollisionHandler::ResolveEnemyCollisions(EnemySpawnerContainer* spawners, Player* player) {
	for (EnemySpawner* spawner : spawners->spawnerList) {
		for (Enemy* enemy : spawner->activeList) {
			if (enemy->dead == false) {
				if (this->CheckCollisions(&enemy->body, &player->body)) {
					ResolveCollision(&enemy->body, &player->body);
					parent->done = true;
					SDL_Log("Collision: [%i, %i] == [%i, %i]", enemy->body.x, enemy->body.y, enemy->sprite.x, enemy->sprite.y);
				}
			}
		}
	}
}

void CollisionHandler::ResolveBulletCollisions(BulletContainer* bulletContainer, EnemySpawnerContainer* spawners) {
	// Biggest O (i hate this)
	for (Bullet* bullet : bulletContainer->bulletList) {
		for (EnemySpawner* spawner : spawners->spawnerList) {
			for (Enemy* enemy : spawner->activeList) {
				if (enemy->dead == false) {
					if (this->CheckCollisions(&bullet->body, &enemy->body)) {
						ResolveCollision(&bullet->body, &enemy->body);
						player->score.Increment();
						bullet->dead = true;
						enemy->dead = true;
					}
				}
			}
		}
	}
}
