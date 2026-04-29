// Related Header
#include "player.h"

// Project Headers
#include "world.h"



// Constructor
Player::Player() {
}

void Player::Init(SDL_Renderer* renderer) {
	height = 50;
	width = 50;
	SetPositionsToCenter(parent->window, width, height, &x, &y);

	body.x = x;
	body.y = y;
	body.h = height;
	body.w = width;

	sprite.Init(x, y, 50, 50, 1);

	colour[0] = 255;
	colour[1] = 0;
	colour[2] = 0;

	alpha = 255;

	maxVelocity = 10;
	velocity.x = 0;
	velocity.y = 0;

	bulletContainer.parent = this;
	bulletContainer.Init();

	score.parent = this;
	score.Init();
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
	sprite.Update(x, y);

	//SDL_Log("PlayerMovement: MoveLeft: %i; MoveRight: %i;Velocity X: %i\nMoveUp:%i; MoveDown: %i; Velocity Y: %i\n\n", moveLeft, moveRight, velocity.x, moveUp, moveDown, velocity.y);

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

	if (x + velocity.x < 0 || x + velocity.x > parent->maxBoundX - width) {
		velocity.x = 0;
	}

	if (y + velocity.y < 0 || y + velocity.y > parent->maxBoundY - height) {
		velocity.y = 0;
	}

	x += velocity.x;
	y += velocity.y;

	if (shoot) {
		bulletContainer.Spawn();
		shoot = false;
	}

	bulletContainer.Update();
}

void Player::Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, colour[0], colour[1], colour[2], alpha);
	sprite.Render(renderer, "./content/player.png");
	bulletContainer.Render(renderer);
}