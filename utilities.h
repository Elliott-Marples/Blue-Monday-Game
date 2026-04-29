#ifndef BLUE_MONDAY_UTILITIES_H_
#define BLUE_MONDAY_UTILITIES_H_

#include "SDL.h"
#include "vector.h"

void SetPositionsToCenter(SDL_Window* window, int width, int height, int* x, int* y);
int GetAngleFromPoints(int destX, int destY, int originX, int originY);

#endif // !BLUE_MONDAY_UTILITIES_H_
