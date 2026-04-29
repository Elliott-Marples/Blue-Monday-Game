#include "utilities.h"

void SetPositionsToCenter(SDL_Window* window, int width, int height, int* x, int* y) {
	int windowWidth, windowHeight;
	
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);
	*x = (windowWidth / 2) - (width / 2);
	*y = (windowHeight / 2) - (height / 2);
}

int GetAngleFromPoints(int destX, int destY, int originX, int originY) {
	int deltaX = destX - originX;
	int deltaY = destY - originY;

	return atan2(deltaY, deltaX);
}