// SDL Library
#include "SDL.h"

// Project Libraries
#include "world.h"

World world;

// Main Function
int main(int argc, char* argv[]) {
	// Ensures SDL is running
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	// Start Game
	world.Init();
	world.Run();

	// Exits Program
	world.Quit();
	SDL_Quit();
	return 0;
}