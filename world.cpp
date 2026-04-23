// Related Header
#include "world.h"

// Constructor
World::World() {

}

// Clears screen to black
void World::Init() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

// Runs gameloop with a fixed framerate
void World::Run() {
	while (!done) {
		timer.Reset();

		Input();
		Update();
		Render();

		if (timer.Get() < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - timer.Get());
		}
	}
}

// Checks for inputs
void World::Input() {
	while (SDL_PollEvent(&event)) {
		// Quits gameloop when event has SDL_Quit flag
		if (event.type == SDL_QUIT) {
			done = true;
		}

		// Checks keys pressed
		if (event.type == SDL_KEYDOWN && event.key.repeat == NULL) {
			switch (event.key.keysym.sym) {
			// Quits gameloop when Escape is pressed
			case SDLK_ESCAPE:
				done = true;
				break;
			
			// Processes W press
			case SDLK_w:
				printf("W has been pressed.\n");
				pressedKeys[SDLK_w] = true;
				break;
			}
		}

		// Checks keys released
		if (event.type == SDL_KEYUP && event.key.repeat == NULL) {
			switch (event.key.keysym.sym) {
			// Processes W release
			case SDLK_w:
				pressedKeys[SDLK_w] = false;
				break;
			}
		}
	}
}

// Updates game world
void World::Update() {

}

// Renders objects to screen
void World::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

// Destroys renderer and window
void World::Quit() {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

	if (window) {
		SDL_DestroyWindow(window);
	}
}