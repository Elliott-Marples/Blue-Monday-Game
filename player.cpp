// Related Header
#include "player.h"

// Project Headers
#include "world.h"



// Constructor
Player::Player() {
}

void Player::Init() {
	x = 150;
	y = 150;
	height = 25;
	width = 25;

	body.x = x;
	body.y = y;
	body.h = height;
	body.w = width;

	colour[0] = 255;
	colour[1] = 0;
	colour[2] = 0;

	alpha = 255;

	maxVelocity = 10;
	velocity.x = 0;
	velocity.y = 0;
}

void Player::Input(int pressedKey, bool isPressed) {
	if (isPressed) {
		switch (pressedKey) {
		case SDLK_w:
			moveUp = true;
			break;

		case SDLK_a:
			moveLeft = true;
			break;

		case SDLK_s:
			moveDown = true;
			break;

		case SDLK_d:
			moveRight = true;
			break;
		}
	}
	else {
		switch (pressedKey) {
		case SDLK_w:
			moveUp = false;
			break;

		case SDLK_a:
			moveLeft = false;
			break;

		case SDLK_s:
			moveDown = false;
			break;

		case SDLK_d:
			moveRight = false;
			break;
		}
	}
}

void Player::Update() {
	body.x = x;
	body.y = y;

	printf("%i,%i;Velocity X: %i\n%i,%i;Velocity Y: %i\n\n", moveLeft, moveRight, velocity.x, moveUp, moveDown, velocity.y);

	if (moveUp && velocity.y > -(maxVelocity)) {
		velocity.y -= 1;
	}
	else if (velocity.y < 0) {
		velocity.y += 1;
	}

	if (moveLeft && velocity.x > -(maxVelocity)) {
		velocity.x -= 1;
	}
	else if (velocity.x < 0) {
		velocity.x += 1;
	}

	if (moveDown && velocity.y < maxVelocity) {
		velocity.y += 1;
	}
	else if (velocity.y > 0) {
		velocity.y -= 1;
	}

	if (moveRight && velocity.x < maxVelocity) {
		velocity.x += 1;
	}
	else if (velocity.x > 0) {
		velocity.x -= 1;
	}

	x += velocity.x;
	y += velocity.y;
}

void Player::Render() {
	SDL_Renderer* renderer = parent->renderer;
	SDL_SetRenderDrawColor(renderer, colour[0], colour[1], colour[2], alpha);
	SDL_RenderFillRect(renderer, &body);
}