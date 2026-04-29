// Related Header
#include "world.h"



// Constructor
World::World() {

}

// Clears screen to black
void World::Init(SDL_Window* window, SDL_Renderer* renderer, std::vector<Mix_Music*> audio) {
	this->window = window;
	this->renderer = renderer;
	this->endTicks = 60000 + SDL_GetTicks();

	SDL_GetWindowSize(window, &maxBoundX, &maxBoundY);

	player.parent = this;
	player.Init(renderer);

	music.parent = this;
	music.Init(audio);

	enemySpawnerContainer.parent = this;
	enemySpawnerContainer.Init(frameRate);

	collisionHandler.parent = this;
	collisionHandler.Init(frameRate, &enemySpawnerContainer, &player);

	level.parent = this;
	level.Init();

	// Randomiser
	srand(time(0));

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

// Runs gameloop with a fixed framerate
void World::Run() {
	while (!done) {
		if (SDL_GetTicks() >= endTicks) {
			done = true;
			win = true;
			printf("Finished at %i secs", endTicks / 1000);
			SDL_Log("Finished at %i secs", endTicks / 1000);
			break;
		}

		timer.Reset();

		Input();
		Update();
		Render();

		if (timer.Get() < DELTA_TIME) {
			SDL_Delay(DELTA_TIME - timer.Get());
		}
	}
	
	end.Init(window, renderer, win);
	end.Run();
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

			case SDLK_f:
				if (!fullscreen) {
					fullscreen = true;
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
				}
				else {
					fullscreen = false;
					SDL_SetWindowFullscreen(window, 0);
				}
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
	music.Update();
	enemySpawnerContainer.Update();
	collisionHandler.Update();
}

// Renders objects to screen
void World::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	player.Render(renderer);
	enemySpawnerContainer.Render(renderer);

	SDL_RenderPresent(renderer);
}

// Destroys renderer and window
void World::Quit() {
	if (music.audio[music.track]) {
		music.Quit();
	}

	if (renderer) {
		SDL_DestroyRenderer(renderer);
	}

	if (window) {
		SDL_DestroyWindow(window);
	}
}