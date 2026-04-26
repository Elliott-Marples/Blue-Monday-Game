// SDL Library
#include "SDL.h"

// Project Libraries
#include "world.h"
#include "splash.h"



// Objects
World world;
Splash splash;

// Main Function
int main(int argc, char* argv[]) {
	// Ensures SDL is running
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	char title[] = "Elliott Marples (29183333): Games Programming Project - Blue Monday";

	// Create Window
	SDL_Window* window = SDL_CreateWindow(title, 250, 250, 640, 360, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Start Game
	world.Init(window, renderer);
	splash.Init(renderer);
	splash.Render();
	world.Run();

	// Exits Program
	world.Quit();
	SDL_Quit();
	return 0;
}