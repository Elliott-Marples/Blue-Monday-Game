// Related Header
#include "timer.h"

// Constructor
Timer::Timer() {
	start = 0;
}

void Timer::Reset() {
	start = SDL_GetTicks();
}

int Timer::Get() {
	return (SDL_GetTicks() - start);
}