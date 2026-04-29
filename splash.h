#ifndef BLUE_MONDAY_SPLASH_H_
#define BLUE_MONDAY_SPLASH_H_

#include "SDL.h"

#include "sprite.h"



// Class
class Splash {
private:
	int time;

	Sprite title;
	int titleWidth = 1280;
	int titleHeight = 720;
	int titleSize = 1;

public:
	Splash();

	SDL_Window* window;
	SDL_Renderer* renderer;

	void Init(SDL_Window* window, SDL_Renderer* renderer);
	void Render();
};

#endif // !BLUE_MONDAY_SPLASH_H_
