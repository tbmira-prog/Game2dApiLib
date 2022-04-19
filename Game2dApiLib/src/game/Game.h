#ifndef _GAME_
#define _GAME_

#include "engine/audio/AudioManager.h"
#include "engine/graph/GraphManager.h"
#include "engine/input/InputManager.h"

#include "engine/input/Controllable.h"
#include "util/Unique.h"

namespace game
{
	class Game : public util::Unique<Game>
	{
	public:
		Game();
		virtual ~Game();

		virtual void LoadMedia() {};
		virtual void FreeMedia() {};

		void Quit(); // HACK Como jogo irá fechar? Isso deveria ser automático. Mas é, o usuário só tem que escolher quando irá fechar o jogo
		void StopPlaying();

		inline const engine::graph::ImageVector& Images() { return images; }
		inline const engine::input::ControllableVector& Controllables() { return controllables; }
		inline const engine::audio::MusicVector& Musics() { return musics; }
		inline const engine::audio::SoundVector& Sounds() { return sounds; }

		void Push(GameObject& object)
		{
			images.push_back(object.image);
			controllables.push_back(object);
		}

	protected:
		engine::graph::ImageVector images; // HACK Automatizar o push, pop e alterar posição de Images e Controllables juntos para um mesmo objeto do jogo
		engine::input::ControllableVector controllables; // E se images e controllables ficassem encapsulados e o usuário só pudesse usar o GameObject
		engine::audio::MusicVector musics;
		engine::audio::SoundVector sounds;
	};

	struct GameObject : public engine::input::Controllable
	{
		GameObject(engine::graph::Image& i) : Controllable(), image(i) {}
		virtual ~GameObject() {}

		engine::graph::Image& image;
		virtual void HandleInput(const engine::input::Input&) = 0;
	};

}

#endif // _GAME_

