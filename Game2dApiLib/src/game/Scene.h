#ifndef _SCENE_
#define _SCENE_

#include "ObjectVector.h"

namespace game
{
	class Game;

	class Scene // HACK Cpy and operator=
	{
	friend class Game;
	friend class MainController;

	public:
		Scene(Game&);
		virtual ~Scene();

		void Start();

		virtual void Logic() = 0;
		
		inline const engine::graph::ImageVector& Images() { return objects.Images(); }
		inline const engine::input::ControllableVector& Controllables() { return objects.Controllables(); }
		inline const engine::audio::SoundVector& Sounds() { return objects.Sounds(); }
		inline engine::audio::Song& CurrentSong() { return objects.CurrentSong(); }
		inline const engine::audio::SongAction SongAction() { return objects.SongAction(); }

		inline bool Playing() const { return playing; }
		inline bool Quit() const { return quit; }

	protected:
		void ChangeSceneTo(Scene*);
		void QuitGame();

		void LoadMedia();

		ObjectVector objects;

	private:
		bool playing, quit;
		Scene* next;
		Game& game;
	};
}

#endif // _SCENE_

/*COMO COMEÇAR O JOGO? (ESCOLHER CENA INICIAL)
Paciencia() : Game()


COMO MUDAR CENA? SERÁ USADO UNIQUE_PTR? OU PTR?
*/