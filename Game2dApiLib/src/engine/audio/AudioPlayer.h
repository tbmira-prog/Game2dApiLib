#ifndef _AUDIO_PLAYER_
#define _AUDIO_PLAYER_

#include "Audio.h"
#include "util/Unique.h"

namespace engine
{
	namespace audio
	{
		class AudioPlayer
		{
		public:
			AudioPlayer() {}
			virtual ~AudioPlayer() {};

			virtual void PlaySoundEffect(const SoundEffect&) = 0;

			virtual void PlayMusic(const Music&) = 0;
			virtual void PauseMusic(const Music&) = 0;
			virtual void StopMusic(const Music&) = 0;
		};
	}
}

#endif _AUDIO_PLAYER_