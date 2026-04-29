// Standard Libraries
#include <vector>
#include <fstream>
#include <iostream>

// SDL Libraries
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

// Project Libraries
#include "world.h"
#include "splash.h"
#include "end.h"



// Log
std::ofstream logFile;
void logData(void* userdata, int category, SDL_LogPriority priority, const char* message) {
	std::cout << message << std::endl;
	logFile << message << std::endl;
}

// Objects
World world;
Splash splash;
End end;
std::vector<Mix_Music*> loop;

// Main Function
int main(int argc, char* argv[]) {
	// Log
	logFile.open("./game_log.txt");

	if (!logFile.is_open()) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Couldn't open log file");
	}

	SDL_LogSetOutputFunction(&logData, NULL);

	// Ensures SDL is running
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 || IMG_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Log("SDL not initialised\n");
		return 1;
	}

	// Music
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		SDL_Log("Audio not found\n");
	}
	else {
		loop = {
			Mix_LoadMUS("./content/loop-1.wav"),
			Mix_LoadMUS("./content/loop-2.wav"),
			Mix_LoadMUS("./content/loop-3.wav"),
			Mix_LoadMUS("./content/loop-4.wav"),
			Mix_LoadMUS("./content/loop-5.wav"),
			Mix_LoadMUS("./content/loop-6.wav")
		};

		Mix_VolumeMusic(64);
	}

	char title[] = "Elliott Marples (29183333): Games Programming Project - Blue Monday";
	
	int windowWidth = 1280;
	int windowHeight = 720;

	// Create Window
	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Start Game
	splash.Init(window, renderer);
	splash.Render();
	world.Init(window, renderer, loop);
	world.Run();
	world.Quit();

	// Exits Program
	logFile.close();
	SDL_Quit();
	IMG_Quit();
	return 0;
}