#ifndef BLUE_MONDAY_ENEMY_H_
#define BLUE_MONDAY_ENEMY_H_

#include "SDL.h"

#include "vector.h"
#include "utilities.h"
#include "sprite.h"



class EnemySpawner;
class Player;

class Enemy {
public:
	Enemy();

	int x, y;
	int width, height;

	SDL_Rect body;
	Sprite sprite;

	int speed;
	float deltaX, deltaY, length;
	Vector velocity;

	int updateRate, updateTimer;

	bool dead;

	int fade;
	int blueness;

	Player* target;
	EnemySpawner* parent;

	void Init(int frameRate);
	void Update();
	void Render(SDL_Renderer* renderer);

	void Fade(SDL_Renderer* renderer);
};

#endif // !BLUE_MONDAY_ENEMY_H_
