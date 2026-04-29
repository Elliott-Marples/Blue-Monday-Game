#ifndef BLUE_MONDAY_SPRITE_H_
#define BLUE_MONDAY_SPRITE_H_

#include "SDL.h"
#include "SDL_image.h"



class Sprite {
private:
	SDL_Surface* surface;
	SDL_Texture* texture;

public:
	Sprite();
	~Sprite();

	SDL_Rect imgRect, bodyRect;
	int x, y;
	int width, height;

	void Init(int x, int y, int imgWidth, int imgHeight, float size);
	void Init(const char path[], int alpha);
	void Update(int x, int y);
	void Render(SDL_Renderer* renderer, const char path[]);
	void Render(SDL_Renderer* renderer, int r, int g, int b, int alpha, const char path[]);
};

#endif // !BLUE_MONDAY_SPRITE_H_
