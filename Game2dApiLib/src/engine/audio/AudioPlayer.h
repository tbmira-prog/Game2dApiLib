#ifndef _AUDIO_PLAYER_
#define _AUDIO_PLAYER_

#include "Audio.h"
#include "util/Unique.h"

namespace engine
{
	namespace audio
	{
		class AudioPlayer : util::Unique<AudioPlayer> // HACK Design desta classe e Audio.h estão inconsistentes. AudioPlayer controla Song, mas SoundEffect usa o AudioPlayer
		{
		public:
			AudioPlayer() : util::Unique<AudioPlayer>(), currentSong(noSong) {}
			virtual ~AudioPlayer() {};

			void ControlMusic(Song&, const SongAction);

		private:
			/*virtual void Play(const Song&) = 0;
			virtual void Pause(const Song&) = 0;
			virtual void Stop(const Song&) = 0;*/

			Song& currentSong;
		};
	}
}

#endif _AUDIO_PLAYER_