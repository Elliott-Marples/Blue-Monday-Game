// Define Guard
#ifndef BLUE_MONDAY_PLAYER_H_
#define BLUE_MONDAY_PLAYER_H_

// SDL Library
#include "SDL.h"

// Project Headers
#include "vector.h"
#include "bullet_container.h"
#include "level.h"
#include "score.h"
#include "utilities.h"
#include "sprite.h"



// Parent
class World;

// Class
class Player {
private:

public:
	Player();

	int x, y;
	int height, width;
	SDL_Rect body;
	Sprite sprite;
	
	int colour[3];
	int alpha;
	
	bool moveUp, moveLeft, moveDown, moveRight;
	
	Vector velocity;
	int accelRate, decelRate, maxVelocity;

	bool shoot;
	BulletContainer bulletContainer;

	Score score;

	World* parent;

	void Init(SDL_Renderer* renderer);
	void Input(int pressedKey, bool isPressed);
	void Update();
	void Render(SDL_Renderer* renderer);
};

// End of Define Guard
#endif // !BLUE_MONDAY_PLAYER_H_
