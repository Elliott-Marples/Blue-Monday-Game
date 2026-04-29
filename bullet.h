#ifndef BLUE_MONDAY_BULLET_H_
#define BLUE_MONDAY_BULLET_H_

#include <cmath>
#include "SDL.h"

#include "vector.h"
#include "utilities.h"
#include "sprite.h"



class BulletContainer;

class Bullet {
private:
	int speed = 20;
	int size = 10;

	int r = 0;
	int g = 0;
	int b = 255;

public:
	Bullet();
	~Bullet();

	int x, y;
	SDL_Rect body;
	Sprite sprite;

	int mouseX, mouseY;
	float deltaX, deltaY, length;
	Vector velocity;

	bool dead;

	BulletContainer* parent;

	void Init();
	void Update();
	void Render(SDL_Renderer* renderer);
};

#endif // !BLUE_MONDAY_BULLET_H_
