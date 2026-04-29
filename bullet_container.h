#ifndef BLUE_MONDAY_BULLET_CONTAINER_H_
#define BLUE_MONDAY_BULLET_CONTAINER_H_

#include <vector>

#include "SDL.h"

#include "vector.h"
#include "bullet.h"



class Player;

class BulletContainer {
public:
	BulletContainer();
	~BulletContainer();

	int x, y;

	std::vector<Bullet*> bulletList;
	Player* parent;

	void Init();
	void Spawn();
	void Clean();
	void Update();
	void Render(SDL_Renderer* renderer);
};

#endif // !BLUE_MONDAY_BULLET_CONTAINER_H_