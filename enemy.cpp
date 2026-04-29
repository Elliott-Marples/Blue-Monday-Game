#include "enemy.h"

#include "enemy_spawner.h"
#include "enemy_spawner_container.h"
#include "world.h"

Enemy::Enemy() {

}

void Enemy::Init(int frameRate) {
	x = parent->x;
	y = parent->y;

	width = 50;
	height = 50;

	body = { x, y, width, height };
	sprite.Init(x, y, width, height, 1);

	speed = parent->parent->enemySpeed;

	updateRate = parent->parent->parent->frameRate * 0.25;
	updateTimer = updateRate;

	fade = 255;
	blueness = 255;
	velocity = { 0, 0 };
	dead = false;

	printf("Enemy Initied\n");
}

void Enemy::Update() {
	body.x = x;
	body.y = y;
	sprite.Update(x, y);

	updateTimer -= 1;

	if (updateTimer <= 0) {
		deltaX = target->x - x;
		deltaY = target->y - y;
		length = sqrt(deltaX * deltaX + deltaY * deltaY);

		if (length != 0) {
			velocity.x = speed * deltaX / length;
			velocity.y = speed * deltaY / length;
		}

		if (speed != parent->parent->enemySpeed) {
			speed = parent->parent->enemySpeed;
		}

		SDL_Log("Enemy Pos - [%i, %i]; Enemy Speed - %d; Enemy Velocity - [%d, %d]\n", x, y, speed, velocity.x, velocity.y);
		updateTimer = updateRate;
	}


	x += velocity.x;
	y += velocity.y;
}

void Enemy::Render(SDL_Renderer* renderer) {
	sprite.Render(renderer, 255, 255, 255, 255, "./content/enemy.png");
}

void Enemy::Fade(SDL_Renderer* renderer) {
	fade -= 5;
	blueness -= 10;

	if (fade < 0) fade = 0;
	if (blueness < 0) blueness = 0;

	sprite.Render(renderer, fade, blueness, blueness, 255, "./content/enemy.png");
}