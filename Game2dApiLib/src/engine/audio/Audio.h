#ifndef _AUDIO_
#define _AUDIO_

#include "util/Unique.h"

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

			virtual void Play(AudioPlayer&) const = 0;
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

		class None final : public Song, public util::Unique<None>
		{
		public:
			None() : Song(), util::Unique<None>() {}
			~None() {}

			bool operator==(const Song& song) const override
			{
				return this == &song;
			}
			
		private:			
			void Play(AudioPlayer&) {} 
			void Pause(AudioPlayer&) {}
			void Stop(AudioPlayer&) {}

			None(const None&) = delete;
			None& operator=(const None&) = delete;
		};

		None noSong; // HACK Resolver Link Warning

		class Silence final : public SoundEffect, public util::Unique<Silence>
		{
		public:
			Silence() : SoundEffect(), util::Unique<Silence>() {}
			~Silence() {}

			void Play(AudioPlayer&) const override {}
		};

		Silence silence; // HACK Resolver Link Warning
	}
}

#endif _AUDIO_