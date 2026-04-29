#include "sprite.h"

Sprite::Sprite() {

}

Sprite::~Sprite() {
	if (texture) {
		SDL_DestroyTexture(texture);
	}
}

void Sprite::Init(int x, int y, int imgWidth, int imgHeight, float size) {
	this->x = x;
	this->y = y;
	this->width = imgWidth * size;
	this->height = imgHeight * size;

	this->imgRect = { 0, 0, imgWidth, imgHeight };
	this->bodyRect = { x, y, width, height };

	if (texture) {
		SDL_SetTextureAlphaMod(texture, 255);
	}
}

void Sprite::Init(const char path[], int alpha) {
	surface = IMG_Load(path);
	SDL_SetColorKey(surface, SDL_TRUE, alpha);
}

void Sprite::Update(int x, int y) {
	this->x = x;
	this->y = y;
	bodyRect.x = x;
	bodyRect.y = y;
}

void Sprite::Render(SDL_Renderer* renderer, const char path[]) {
	if (!texture) {
		if (!surface) {
			texture = IMG_LoadTexture(renderer, path);
		}
		else {
			texture = SDL_CreateTextureFromSurface(renderer, surface);
		}
	}
	SDL_RenderCopy(renderer, texture, &imgRect, &bodyRect);
}

void Sprite::Render(SDL_Renderer* renderer, int r, int g, int b, int alpha, const char path[]) {
	if (!texture) {
		if (!surface) {
			texture = IMG_LoadTexture(renderer, path);
		}
		else {
			texture = SDL_CreateTextureFromSurface(renderer, surface);
		}
	}
	SDL_SetTextureAlphaMod(texture, alpha);
	SDL_SetTextureColorMod(texture, r, g, b);
	SDL_RenderCopy(renderer, texture, &imgRect, &bodyRect);
}