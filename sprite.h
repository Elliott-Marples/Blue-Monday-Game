#ifndef BLUE_MONDAY_SPRITE_H_
#define BLUE_MONDAY_SPRITE_H_

#include "SDL.h"
#include "SDL_image.h"



class Sprite {
private:
	SDL_Texture* texture;

public:
	Sprite();

	SDL_Renderer* renderer;

	SDL_Rect imgRect, bodyRect;
	int x, y;
	int width, height;

	void Init(SDL_Renderer* renderer, int x, int y, int imgWidth, int imgHeight, float size, const char path[]);
	void Init(SDL_Renderer* renderer, int x, int y, int imgWidth, int imgHeight, float size, const char path[], int alpha);
	void Render();
};

#endif // !BLUE_MONDAY_SPRITE_H_
