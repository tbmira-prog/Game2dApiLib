#ifndef _GAME_
#define _GAME_

#include "util/Unique.h"

#include "engine/audio/AudioManager.h"
#include "engine/graph/GraphManager.h"
#include "engine/input/InputManager.h"

#include "GameObject.h"

namespace game
{
	class Game : public util::Unique<Game> // TO_DO Separar Game em subclasses: cena, vetores
	{
	public:
		Game();
		virtual ~Game();

		void StartScene();
		void FinishScene();
		
		inline bool Quit() const;
		inline bool PlayingScene() const;

		inline const engine::graph::ImageVector& Images() { return images; } // TO_DO Impedir que modifiquem a ordem dos vetores fora de Game
		inline engine::input::ControllableVector& Controllables() { return controllables; } // TO_DO Retornar const & ou só & ?
		inline engine::audio::SoundVector& Sounds() { return sounds; }
		inline engine::audio::Song& CurrentSong() { return song; }
		inline const engine::audio::SongAction SongAction() { return songAction; }

		void Push(GameObject& object); // HACK Fazer sobrecargas dessa função para sounds, background, etc.

	protected: // TODO Limitar acesso para images e controllables
		inline void QuitGame();
		inline void StopScene();

		engine::audio::SoundVector sounds;
		engine::audio::Song& song;
		engine::audio::SongAction songAction;

	private:
		engine::graph::ImageVector images;
		engine::input::ControllableVector controllables;

		bool quit;
		bool playingScene;

		virtual void LoadMedia() {};
		virtual void FreeMedia() {};

		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;
	};
}

#endif // _GAME_

