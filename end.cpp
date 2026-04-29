#include "end.h"

End::End() {

}

void End::Init(SDL_Window* window, SDL_Renderer* renderer, bool win) {
	this->window = window;
	this->renderer = renderer;
	this->win = win;

	sprite.Init(0, 0, 1280, 720, 1);
}

void End::Run() {

	Render();
	while (!done) {
		Input();
	}
}

void End::Input() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			done = true;
		}
		
		// Checks keys pressed
		if (event.type == SDL_KEYDOWN && event.key.repeat == NULL) {
			if (event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_RETURN) {
				// Quits gameloop when Escape is pressed
				done = true;
				break;
			}
		}
	}
}

void End::Render() {
	int b;

	if (win) {
		b = 50;
	}
	else
	{
		b = 25;
	}

	SDL_SetRenderDrawColor(renderer, 25, 25, b, 255);
	SDL_RenderClear(renderer);
	if (!win) {
		sprite.Render(renderer, "./content/end_loss.png");
	}
	else {
		sprite.Render(renderer, "./content/end_win.png");
	}
	SDL_RenderPresent(renderer);
}