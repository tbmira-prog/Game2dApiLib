#ifndef _AUDIO_MANAGER_
#define _AUDIO_MANAGER_

#include <vector>

#include "AudioPlayer.h"
#include "util/Unique.h"

namespace engine
{
	namespace audio
	{
		typedef std::vector<std::reference_wrapper<SoundEffect>> SoundVector;

		class AudioManager final : public util::Unique<AudioManager>
		{
		public:
			AudioManager(AudioPlayer&);
			~AudioManager();

			void PlaySoundEffects(SoundVector);

			inline void ControlMusic(Song&, const SongAction);

		private:
			AudioPlayer& audioPlayer;

			AudioManager(const AudioManager&) = delete;
			AudioManager& operator=(const AudioManager&) = delete;
		};
	}
}

#endif _AUDIO_MANAGER_