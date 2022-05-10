#include "AudioManager.h"
using namespace engine::audio;

AudioManager::AudioManager(AudioPlayer& newAudioPlayer) : Unique<AudioManager>(), audioPlayer(newAudioPlayer) {}

AudioManager::~AudioManager() {}

void AudioManager::PlaySoundEffects(SoundVector sounds)
{
	for (auto sound : sounds)
	{
		sound.get().Play(audioPlayer);
		sound.get() = silence;
	}
}

void AudioManager::ControlMusic(Song& song, const SongAction action)
{
	audioPlayer.ControlMusic(song, action);
}
