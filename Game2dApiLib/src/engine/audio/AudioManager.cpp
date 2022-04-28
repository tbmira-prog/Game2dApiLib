#include "AudioManager.h"
using namespace engine::audio;

AudioManager::AudioManager(AudioPlayer& newAudioPlayer) : Unique<AudioManager>(), audioPlayer(newAudioPlayer) {}

AudioManager::~AudioManager() {}

void AudioManager::PlaySoundEffects(SoundVector sounds)
{
	for (auto sound : sounds)
		//audioPlayer.PlaySoundEffect(sound);
		sound.get().Play(audioPlayer);

	sounds.erase(sounds.begin(), sounds.end());
}

void AudioManager::ControlMusic(Song& song, const SongAction action)
{
	audioPlayer.ControlMusic(song, action);
}
