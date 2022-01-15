#ifndef _AUDIO_
#define _AUDIO_

namespace audio // UNDONE Complementar definição das classes de audio (construtor de copia, operator=, etc.)
{
	class SoundEffect
	{
	public:
		SoundEffect() {};
		virtual ~SoundEffect() {};
	};

	class Music
	{
	public:
		Music() {};
		virtual ~Music() {};
	};
}

#endif _AUDIO_