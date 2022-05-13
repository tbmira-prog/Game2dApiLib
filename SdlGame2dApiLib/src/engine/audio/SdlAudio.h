#ifndef _SDL_AUDIO_
#define _SDL_AUDIO_

#include <exception>
#include <memory>
#include <string>

#include <SDL_mixer.h>

#include "engine/audio/Audio.h"

namespace engine
{
	namespace audio
	{
		class AudioPlayer;

		namespace sdl
		{
			class SdlSoundEffect final : public engine::audio::SoundEffect
			{
			public:
				SdlSoundEffect();
				explicit SdlSoundEffect(Mix_Chunk* newChunk);
				explicit SdlSoundEffect(std::shared_ptr<Mix_Chunk> newChunk);
				explicit SdlSoundEffect(const std::string& filePath);

				SdlSoundEffect(const SdlSoundEffect&);
				SdlSoundEffect& operator=(const SdlSoundEffect&);

				~SdlSoundEffect();

				void ChangeChunk(const std::string& filePath);

				void Play(AudioPlayer&) override;

			private:
				std::shared_ptr<Mix_Chunk> pChunk;
			};

			inline void DeleteChunk(Mix_Chunk* pChunk)
			{
				if (pChunk != NULL)
				{
					Mix_FreeChunk(pChunk);
					pChunk = nullptr;
				}
			}

			struct InvalidChunk : public std::exception
			{
				const char* what() const override { return "Invalid chunk was passed to sdl::SoundEffect!\n"; }
			};

			class SdlMusic final : public engine::audio::Song
			{
			public:
				SdlMusic();
				explicit SdlMusic(Mix_Music* pNewMusic);
				explicit SdlMusic(std::shared_ptr<Mix_Music> pNewMusic);
				explicit SdlMusic(const std::string& filePath);

				SdlMusic(const SdlMusic&);
				SdlMusic& operator=(const SdlMusic&);

				~SdlMusic();

				void ChangeMusic(const std::string& filePath);

				void Play(AudioPlayer&) override;
				void Pause(AudioPlayer&) override;
				void Stop(AudioPlayer&) override;

			private:
				std::shared_ptr<Mix_Music> pMusic;
			};

			inline void DeleteMusic(Mix_Music* pMusic)
			{
				if (pMusic != NULL)
				{
					Mix_FreeMusic(pMusic);
					pMusic = nullptr;
				}
			}

			struct InvalidMusic : public std::exception
			{
				const char* what() const override { return "Invalid music was passed to sdl::Song!\n"; }
			};
		}
	}
}

#endif // _SDL_AUDIO_