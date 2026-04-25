// Define Guard
#ifndef BLUE_MONDAY_TIMER_H_
#define BLUE_MONDAY_TIMER_H_

// SDL Library
#include "SDL.h"



// Class
class Timer {
private:
	int start;

public:
	Timer();

	void Reset();
	int Get();
};

// End of Define Guard
#endif // !BLUE_MONDAY_TIMER_H_
