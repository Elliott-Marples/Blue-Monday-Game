#include "music.h"

#include "world.h"

Music::Music() {

}

void Music::Init(std::vector<Mix_Music*> audio) {
	this->audio = audio;
	beat = 0;
    track = 0;

	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(audio[track], 0);
		timer.Reset();
	}

}

void Music::Next() {
    if (track < 6) {
        track++;
    }
}

void Music::Update() {
    if (timer.Get() >= end) {
        Mix_PlayMusic(audio[track], 0);
        timer.Reset();
        beat = 0;
    }

    while (beat < timestamps.size() &&
        timer.Get() >= timestamps[beat]) {

        parent->player.shoot = true;
        beat++;
    }

    if (beat >= timestamps.size()) {
        beat = 0;
    }
}

void Music::Quit() {
	Mix_FreeMusic(audio[track]);
	Mix_CloseAudio();
}