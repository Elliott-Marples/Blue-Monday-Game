#ifndef BLUE_MONDAY_SPLASH_H_
#define BLUE_MONDAY_SPLASH_H_

#include "SDL.h"

#include "sprite.h"



// Class
class Splash {
private:
	int time;
	Sprite title;

public:
	Splash();

	SDL_Renderer* renderer;

	void Init(SDL_Renderer* renderer);
	void Render();
};

#endif // !BLUE_MONDAY_SPLASH_H_
