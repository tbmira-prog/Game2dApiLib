#ifndef _GAME_
#define _GAME_

#include <memory>

#include <util/Unique.h>

#include "Scene.h"

namespace engine
{
	class Engine;
}

namespace game
{
	class Game : public util::Unique<Game>
	{
	public:
		Game(engine::Engine& engine, Scene*);
		virtual ~Game();

	private:
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;

	public:
		Scene* pCurrentScene;
		void ChangeScene();
	};
}

#endif // _GAME_
