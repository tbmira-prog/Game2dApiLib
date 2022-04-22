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

		void StartScene();
		void FinishScene();
		
		inline bool Quit();
		inline bool PlayingScene();

		inline const engine::graph::ImageVector& Images() { return images; }
		inline const engine::input::ControllableVector& Controllables() { return controllables; }
		inline const engine::audio::MusicVector& Musics() { return musics; }
		inline const engine::audio::SoundVector& Sounds() { return sounds; }

		void Push(GameObject& object);

	protected:
		inline void QuitGame();
		inline void StopScene();

		engine::graph::ImageVector images; // HACK Automatizar o push, pop e alterar posição de Images e Controllables juntos para um mesmo objeto do jogo
		engine::input::ControllableVector controllables; // E se images e controllables ficassem encapsulados e o usuário só pudesse usar o GameObject
		engine::audio::MusicVector musics;
		engine::audio::SoundVector sounds;

	private:
		bool quit;
		bool playingScene;

		virtual void LoadMedia() {};
		virtual void FreeMedia() {};
	};

	struct GameObject : public engine::input::Controllable
	{
		explicit GameObject(engine::graph::Image& i) : Controllable(), image(i) {}
		virtual ~GameObject() {}

		engine::graph::Image& image;
		virtual void HandleInput(const engine::input::Input&) = 0;

		GameObject(const GameObject&); // TODO Como será feita a cópia da imagem?
		GameObject& operator=(const GameObject&); // TODO Como será feita a cópia da imagem?
	};

}

#endif // _GAME_

