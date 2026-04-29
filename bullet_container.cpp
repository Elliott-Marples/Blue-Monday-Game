#include "bullet_container.h"
#include "player.h"

BulletContainer::BulletContainer() {

}

BulletContainer::~BulletContainer() {
	for (Bullet* element : bulletList) {
		delete element;
		SDL_Log("Deleted bullet\n");
	}
}

void BulletContainer::Init() {
	this->x = parent->x + (parent->width / 2);
	this->y = parent->y + (parent->height / 2);
}

void BulletContainer::Spawn() {
	Bullet* bullet = new Bullet();
	bullet->parent = this;
	bullet->Init();
	this->bulletList.push_back(bullet);
}

void BulletContainer::Clean() {
	for (int i = 0; i < bulletList.size();) {
		if (bulletList[i]->dead) {
			delete bulletList[i];
			bulletList.erase(bulletList.begin() + i);
		}
		else {
			i++;
		}
	}
}

void BulletContainer::Update() {
	if (this->x != parent->x + (parent->width / 2)) {
		this->x = parent->x + (parent->width / 2);
	}

	if (this->y != parent->y + (parent-> height/ 2)) {
		this->y = parent->y + (parent->height / 2);
	}

	for (Bullet* element : bulletList) {
		element->Update();
	}
}

void BulletContainer::Render(SDL_Renderer* renderer) {
	for (Bullet* element : bulletList) {
		element->Render(renderer);
	}
}