#include "AudioManager.h"
using namespace engine::audio;

AudioManager::AudioManager(AudioPlayer& newAudioPlayer) : Unique<AudioManager>(), audioPlayer(newAudioPlayer) {}

AudioManager::~AudioManager() {}

AudioManager::PlaySoundEffects(SoundVector sounds)
{
	for (auto sound : sounds)
		audioPlayer.PlaySoundEffect(sound);
}

AudioManager::

AudioManager::

AudioManager::

AudioManager::

AudioManager::

AudioManager::