#ifndef _AUDIO_MANAGER_
#define _AUDIO_MANAGER_

#include <vector>

#include "AudioPlayer.h"
#include "util/Unique.h"

namespace engine
{
	namespace audio
	{
		typedef std::vector<std::reference_wrapper<Music>> MusicVector;
		typedef std::vector<std::reference_wrapper<SoundEffect>> SoundVector;

		class AudioManager : public Unique<AudioManager> // UNDONE Definir e implementar funções de AudioManager
		{
		public:
			AudioManager(AudioPlayer&);
			~AudioManager();

			void PlaySoundEffects(SoundVector);

			void PlayMusics(MusicVector);
			void PlayList(MusicVector);
			void StopMusic();
			void StopMusic(const Music&);
		private:
			AudioPlayer& audioPlayer;
		};
	}
}

#endif _AUDIO_MANAGER_