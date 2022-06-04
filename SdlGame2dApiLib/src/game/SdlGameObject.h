#ifndef _SDL_GAME_OBJECT_
#define _SDL_GAME_OBJECT_

#include <game/GameObject.h>

#include <engine/graph/SdlImage.h>
#include <engine/audio/SdlAudio.h>

namespace game
{
	namespace sdl
	{
		class SdlGameObject : public game::GameObject
		{
		public:
			SdlGameObject();
			~SdlGameObject();

			virtual void HandleInput(const engine::input::Input&) = 0;
			virtual void LoadMedia() = 0;

			void SetImage(const engine::graph::sdl::SdlImage&);
			void SetSoundEffect(const engine::audio::sdl::SdlSoundEffect&);
			void SetSong(const engine::audio::sdl::SdlMusic&);

			engine::graph::sdl::RenderingConfiguration& ImageConfigure();
			const engine::graph::sdl::RenderingConfiguration& ImageConfiguration() const;

		private:
			engine::graph::sdl::SdlImage sdlImage;
			engine::audio::sdl::SdlSoundEffect sdlSoundEffect;
			engine::audio::sdl::SdlMusic sdlMusic;
		};
	}
}

#endif // _SDL_GAME_OBJECT_