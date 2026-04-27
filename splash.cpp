#include "splash.h"

Splash::Splash() {

}

void Splash::Init(SDL_Renderer* renderer) {
	time = 5;
	this->renderer = renderer;

	title.Init(renderer, 250, 50, 900, 254, 0.25, "content/title_sprite.png");
}

void Splash::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	title.Render();
	SDL_RenderPresent(renderer);
	SDL_Delay(time * 1000);
}