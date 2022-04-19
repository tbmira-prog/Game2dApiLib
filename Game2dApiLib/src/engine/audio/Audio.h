#ifndef _AUDIO_
#define _AUDIO_

namespace engine
{
	namespace audio // UNDONE Complementar definição das classes de audio (construtor de copia, operator=, etc.)
	{
		class SoundEffect
		{
		public:
			SoundEffect() {};
			virtual ~SoundEffect() {};

			SoundEffect(const SoundEffect&) = default;
			SoundEffect& operator=(const SoundEffect&) = default;
		};

		class Music
		{
		public:
			Music() {};
			virtual ~Music() {};

			Music(const Music&) = default;
			Music& operator=(const Music&) = default;
		};
	}
}

#endif _AUDIO_