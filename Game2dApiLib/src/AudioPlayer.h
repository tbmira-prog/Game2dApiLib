#ifndef _AUDIO_PLAYER_
#define _AUDIO_PLAYER_

#include "Audio.h"
#include "Unique.h"

namespace audio
{
	class AudioPlayer // TODO : public Unique
	{
	public:
		AudioPlayer() {}
		~AudioPlayer() {};

		virtual void PlaySoundEffect(const SoundEffect&) = 0;
		
		virtual void PlayMusic(const Music&) = 0;
		virtual void PauseMusic(const Music&) = 0;
		virtual void StopMusic(const Music&) = 0;
	};
}

#endif _AUDIO_PLAYER_