#include "Audio.h"
using namespace engine::audio;

Song::Song(const Song&) : playing(false) {}

Song& Song::operator=(const Song& other)
{
	playing = false;
	return *this;
}
