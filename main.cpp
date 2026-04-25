// SDL Library
#include "SDL.h"

// Project Libraries
#include "world.h"



// Objects
World world;

// Main Function
int main(int argc, char* argv[]) {
	// Ensures SDL is running
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	// Create Window
	SDL_Window* window = SDL_CreateWindow("Blue Monday", 250, 250, 640, 360, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Start Game
	world.Init(window, renderer);
	world.Run();

	// Exits Program
	world.Quit();
	SDL_Quit();
	return 0;
}