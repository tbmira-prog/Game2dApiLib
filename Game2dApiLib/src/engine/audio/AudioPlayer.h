#ifndef _AUDIO_PLAYER_
#define _AUDIO_PLAYER_

#include "Audio.h"
#include "NullAudio.h"
#include "util/Unique.h"

namespace engine
{
	namespace audio
	{
		class AudioPlayer : public util::Unique<AudioPlayer> // TO_DO Design desta classe e Audio.h estão inconsistentes. AudioPlayer controla Song, mas SoundEffect usa o AudioPlayer
		{
		public:
			AudioPlayer() : util::Unique<AudioPlayer>(), currentSong(noSong), muted(false) {}
			virtual ~AudioPlayer() {};

			void ControlMusic(Song&, const SongAction);
			inline bool Muted() const { return muted; }

		protected:
			Song& currentSong;
			bool muted;
		};
	}
}

#endif _AUDIO_PLAYER_