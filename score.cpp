#include "score.h"

#include "player.h"
#include "world.h"

Score::Score() {

}

void Score::Init() {
	value = 0;
}

void Score::Increment() {
	value++ * parent->parent->level.value;
	printf("Score: %i\n", value);
	SDL_Log("Score: %i\n", value);
	if (value % 4 == 0) {
		parent->parent->level.Increment();
	}
	if (value == 50) {
		this->Prolong();
	}
}

void Score::Prolong() {
	parent->parent->endTicks += 15000;
	printf("15 seconds added for reaching score of 25\n!");
	SDL_Log("15 seconds added for reaching score of 25\n!");
}