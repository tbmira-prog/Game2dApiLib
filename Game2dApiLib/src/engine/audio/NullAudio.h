#ifndef _NULL_AUDIO_
#define _NULL_AUDIO_

#include "util/Unique.h"
#include "Audio.h"

namespace engine
{
	namespace audio
	{
		class NullSong final : public Song//, public util::Unique<NullSong>
		{
		public:
			NullSong() : Song()/*, util::Unique<NullSong>()*/ {}
			~NullSong() {}

			bool operator==(const Song& song) const override
			{
				return this == &song;
			}

		private:
			void Play(AudioPlayer&) {}
			void Pause(AudioPlayer&) {}
			void Stop(AudioPlayer&) {}

			NullSong(const NullSong&) = delete;
			NullSong& operator=(const NullSong&) = delete;
		};

		static NullSong noSong;

		class NullSoundEffect final : public SoundEffect//, public util::Unique<NullSoundEffect>
		{
		public:
			NullSoundEffect() : SoundEffect()/*, util::Unique<NullSoundEffect>()*/ {}
			~NullSoundEffect() {}

			void Play(AudioPlayer&) override {}
		};

		static NullSoundEffect silence; // HACK Resolver Link Warning
	}
}

#endif // _NULL_AUDIO_