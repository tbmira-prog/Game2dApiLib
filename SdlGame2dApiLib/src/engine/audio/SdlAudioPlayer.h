#ifndef _SDL_AUDIO_PLAYER_
#define _SDL_AUDIO_PLAYER_

#include "engine/audio/AudioPlayer.h"
#include "SdlAudio.h"

namespace engine
{
	namespace audio
	{
		namespace sdl
		{
			class SdlAudioPlayer : public AudioPlayer
			{
			public:
				SdlAudioPlayer();
				~SdlAudioPlayer();
			};

			struct FailedToInitializateSDLAudio : public std::exception
			{
				const char* what() const override { return "Failed to create AudioPlayer!\n"; }
			};
		}
	}
}

#endif // _SDL_AUDIO_PLAYER_