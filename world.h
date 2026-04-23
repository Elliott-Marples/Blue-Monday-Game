// Define Guard
#ifndef BLUE_MONDAY_WORLD_H_
#define BLUE_MONDAY_WORLD_H_

// Standard Libraries
#include <cstdio>

// SDL Library
#include "SDL.h"

// Project Libraries
#include "timer.h"

// Definitions
#define MAX_KEYS (256)

// Class
class World {
private:
	Timer timer;
	const int DELTA_TIME = 50;
	bool done = false;

public:
	World();

	// SDL Properties
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	// Keyboard Handler
	bool pressedKeys[MAX_KEYS];

	// Start Functions
	void Init();
	void Run();

	// Game Loop Functions
	void Input();
	void Update();
	void Render();

	// End Functions
	void Quit();
};

// End of Define Guard
#endif // !BLUE_MONDAY_WORLD_H_
