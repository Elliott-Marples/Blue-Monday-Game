#include "splash.h"

Splash::Splash() {

}

void Splash::Init(SDL_Renderer* renderer) {
	title.x = 200;
	title.y = 50;
	title.h = 50;
	title.w = 200;

	time = 5;

	this->renderer = renderer;
}

void Splash::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &title);
	SDL_RenderPresent(renderer);
	SDL_Delay(time * 1000);
}