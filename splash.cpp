#include "splash.h"
#include "utilities.h"

Splash::Splash() {

}

void Splash::Init(SDL_Window* window, SDL_Renderer* renderer) {
	time = 5;
	this->renderer = renderer;
	this->window = window;

	int titleX, titleY;
	SetPositionsToCenter(window, titleWidth, titleHeight, &titleX, &titleY);

	title.Init(titleX, titleY, titleWidth, titleHeight, titleSize);
}

void Splash::Render() {
	SDL_SetRenderDrawColor(renderer, 25, 25, 25, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	title.Render(renderer, "./content/title_sprite.png");
	SDL_RenderPresent(renderer);
	SDL_Delay(time * 1000);
}