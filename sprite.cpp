#include "sprite.h"

Sprite::Sprite() {

}

void Sprite::Init(SDL_Renderer* renderer, int x, int y, int imgWidth, int imgHeight, float size, const char path[]) {
	this->x = x;
	this->y = y;
	this->width = imgWidth * size;
	this->height = imgHeight * size;

	this->imgRect = { 0, 0, imgWidth, imgHeight };
	this->bodyRect = { x, y, width, height };

	this->renderer = renderer;
	texture = IMG_LoadTexture(renderer, path);
}

void Sprite::Init(SDL_Renderer* renderer, int x, int y, int imgWidth, int imgHeight, float size, const char path[], int alpha) {
	SDL_Surface* surface = IMG_Load(path);
	SDL_SetColorKey(surface, SDL_TRUE, alpha);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Sprite::Render() {
	SDL_RenderCopy(renderer, texture, &imgRect, &bodyRect);
}