#include "level.h"

#include "world.h"

Level::Level() {

}

void Level::Init() {
	value = 1;
	this->container = &parent->enemySpawnerContainer;
	this->frameRate = parent->frameRate;
}

void Level::Increment() {
	value++;
	printf("Level %i reached\n", value);
	SDL_Log("Level %i reached\n", value);
	LevelUp();
}

void Level::LevelUp() {
	if (container->spawnRate > frameRate) {
		container->spawnRate -= frameRate / 2;
	}

	if (value % 2 == 0) {
		container->enemySpeed++;
		parent->music.Next();
	}

	if (value % 3 == 0) {
		container->spawnNum++;
	}
}