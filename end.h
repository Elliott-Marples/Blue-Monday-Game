#ifndef BLUE_MONDAY_END_H_
#define BLUE_MONDAY_END_H_

#include "SDL.h"
#include "sprite.h"



class End {
public:
	End();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	Sprite sprite;

	bool done = false;
	bool win;

	void Init(SDL_Window* window, SDL_Renderer* renderer, bool win);
	void Run();
	void Input();
	void Render();
};

#endif // !BLUE_MONDAY_END_H_
