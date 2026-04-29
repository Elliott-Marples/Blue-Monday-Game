// Define Guard
#ifndef BLUE_MONDAY_WORLD_H_
#define BLUE_MONDAY_WORLD_H_

// Standard Libraries
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

// SDL Library
#include "SDL.h"
#include "SDL_mixer.h"

// Project Libraries
#include "timer.h"
#include "player.h"
#include "music.h"
#include "enemy_spawner_container.h"
#include "collision_handler.h"
#include "level.h"
#include "end.h"

// Definitions
#define MAX_KEYS (256)
#define FRAME_RATE (60)



// Class
class World {
private:
	// Objects
	Timer timer;
	End end;

	// Properties
	const int DELTA_TIME = 1000 / FRAME_RATE;

public:
	World();

	// SDL Properties
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	
	// Public Objects
	Player player;
	Music music;
	EnemySpawnerContainer enemySpawnerContainer;
	CollisionHandler collisionHandler;
	Level level;

	// Keyboard Handler
	bool pressedKeys[MAX_KEYS];
	
	// Done Requirements
	int endTicks;
	bool done = false;
	bool win = false;

	// Bounds
	int maxBoundX, maxBoundY;
	bool fullscreen = false;

	// Frame Rate (per second)
	int frameRate = FRAME_RATE;

	// Start Functions
	void Init(SDL_Window* window, SDL_Renderer* renderer, std::vector<Mix_Music*> audio);
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
