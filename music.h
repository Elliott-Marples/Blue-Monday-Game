#ifndef BLUE_MONDAY_MUSIC_H_
#define BLUE_MONDAY_MUSIC_H_


#include <vector>

#include "SDL.h"
#include "SDL_mixer.h"

#include "timer.h"



class World;

class Music {
private:
	Timer timer;
	int end = 3675;
	std::vector<int> timestamps = { 370, 830, 1291, 1406, 1521, 1636, 1751, 1866, 1981, 2097, 2212, 2672, 3133, 3593 };

public:
	Music();

	std::vector<Mix_Music*> audio;
	int track;
	int beat;

	World* parent;

	void Init(std::vector<Mix_Music*> audio);
	void Next();
	void Update();
	void Quit();
};

#endif // !BLUE_MONDAY_MUSIC_H_
