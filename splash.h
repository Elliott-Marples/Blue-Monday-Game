#ifndef BLUE_MONDAY_SPLASH_H_
#define BLUE_MONDAY_SPLASH_H_

#include "SDL.h"



// Class
class Splash {
private:
	int time;
	SDL_Rect title;
	SDL_Rect subtitle;

public:
	Splash();

	SDL_Renderer* renderer;

	void Init(SDL_Renderer* renderer);
	void Render();
};

#endif // !BLUE_MONDAY_SPLASH_H_
