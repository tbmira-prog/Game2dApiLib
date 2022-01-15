#ifndef _AUDIO_MANAGER_
#define _AUDIO_MANAGER_

#include "AudioPlayer.h"
#include "Unique.h"

namespace audio
{
	class AudioManager : public Unique
	{
	public:
		AudioManager(AudioPlayer&);
		~AudioManager();

		
	private:
		AudioPlayer& audioPlayer;
	};
}

#endif _AUDIO_MANAGER_