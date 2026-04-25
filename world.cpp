// Related Header
#include "world.h"



// Constructor
World::World() {

}

// Clears screen to black
void World::Init(SDL_Window* window, SDL_Renderer* renderer) {
	this->window = window;
	this->renderer = renderer;

	player.Init();
	player.parent = this;

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
			
			// Processes w press
			case SDLK_w:
				pressedKeys[SDLK_w] = true;
				player.Input(SDLK_w, true);
				break;

				// Processes a press
			case SDLK_a:
				pressedKeys[SDLK_a] = true;
				player.Input(SDLK_a, true);
				break;

				// Processes s press
			case SDLK_s:
				pressedKeys[SDLK_s] = true;
				player.Input(SDLK_s, true);
				break;

				// Processes d press
			case SDLK_d:
				pressedKeys[SDLK_d] = true;
				player.Input(SDLK_d, true);
				break;
			}
		}

		// Checks keys released
		if (event.type == SDL_KEYUP && event.key.repeat == NULL) {
			switch (event.key.keysym.sym) {
			// Processes w release
			case SDLK_w:
				pressedKeys[SDLK_w] = false;
				player.Input(SDLK_w, false);
				break;

				// Processes a release
			case SDLK_a:
				pressedKeys[SDLK_a] = false;
				player.Input(SDLK_a, false);
				break;

				// Processes s release
			case SDLK_s:
				pressedKeys[SDLK_s] = false;
				player.Input(SDLK_s, false);
				break;

				// Processes d release
			case SDLK_d:
				pressedKeys[SDLK_d] = false;
				player.Input(SDLK_d, false);
				break;
			}
		}
	}
}

// Updates game world
void World::Update() {
	player.Update();
}

// Renders objects to screen
void World::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	player.Render();

	SDL_RenderPresent(renderer);
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