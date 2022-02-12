#ifndef _AUDIO_MANAGER_
#define _AUDIO_MANAGER_

#include "AudioPlayer.h"
#include "Unique.h"

namespace audio
{
	class AudioManager : public Unique<AudioManager> // UNDONE Definir e implementar funções de AudioManager
	{
	public:
		AudioManager(AudioPlayer&);
		~AudioManager();

		
	private:
		AudioPlayer& audioPlayer;
	};
}

#endif _AUDIO_MANAGER_