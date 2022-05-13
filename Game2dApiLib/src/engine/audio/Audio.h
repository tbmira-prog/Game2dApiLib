#ifndef _AUDIO_
#define _AUDIO_

namespace engine
{
	namespace audio
	{
		class AudioPlayer;

		enum class SongAction {PLAY, PAUSE, STOP};

		class SoundEffect
		{
		public:
			SoundEffect() {};
			virtual ~SoundEffect() {};

			SoundEffect(const SoundEffect&) = default;
			SoundEffect& operator=(const SoundEffect&) = default;

			virtual void Play(AudioPlayer&) = 0;
		};

		class Song
		{
		public:
			Song() : playing(false) {};
			virtual ~Song() {};

			Song(const Song&);
			Song& operator=(const Song&);

			virtual bool operator==(const Song&) const = 0;
			bool operator!=(const Song& s) const
			{
				return !(*this == s);
			}

			virtual void Play(AudioPlayer&) = 0;
			virtual void Pause(AudioPlayer&) = 0;
			virtual void Stop(AudioPlayer&) = 0;

			inline bool Playing() const { return playing; }

		protected:
			bool playing;
		};

		struct SongControl // TO_DO Vai usar esta struct SongControl?
		{
			Song& song;
			SongAction action;
		};
	}
}

#endif // _AUDIO_