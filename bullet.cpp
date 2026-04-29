#include "bullet.h"

#include "bullet_container.h"
#include "world.h"

Bullet::Bullet() {

}

Bullet::~Bullet() {

}

void Bullet::Init() {
	this->x = parent->x;
	this->y = parent->y;

	this->body = {x, y, size, size};
	sprite.Init(x, y, size, size, 1);

	SDL_GetMouseState(&mouseX, &mouseY);

	deltaX = mouseX - x;
	deltaY = mouseY - y;
	length = sqrt(deltaX * deltaX + deltaY * deltaY);

	if (length != 0) {
		velocity.x = speed * deltaX / length;
		velocity.y = speed * deltaY / length;
	}

	dead = false;
}

void Bullet::Update() {
	body.x = x;
	body.y = y;
	sprite.Update(x, y);

	if (x < 0 || y < 0 || x > parent->parent->parent->maxBoundX || y > parent->parent->parent->maxBoundY) {
		dead = true;
	}

	x += velocity.x;
	y += velocity.y;
}

void Bullet::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	sprite.Render(renderer, "./content/bullet.png");
}