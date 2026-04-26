// Define Guard
#ifndef BLUE_MONDAY_PLAYER_H_
#define BLUE_MONDAY_PLAYER_H_

// SDL Library
#include "SDL.h"

// Project Headers
#include "vector.h"



// Parent
class World;

// Class
class Player {
private:
	Vector velocity;
	SDL_Rect body;

public:
	Player();

	int x, y;
	int height, width;
	
	int colour[3];
	int alpha;
	
	bool moveUp, moveLeft, moveDown, moveRight;
	bool shoot;
	int accelRate, decelRate, maxVelocity;

	World* parent;

	void Init();
	void Input(int pressedKey, bool isPressed);
	void Update();
	void Render();
};

// End of Define Guard
#endif // !BLUE_MONDAY_PLAYER_H_
