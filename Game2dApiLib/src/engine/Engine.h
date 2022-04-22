#ifndef _ENGINE_
#define _ENGINE_

#include <functional>
#include <memory>

#include "audio/AudioManager.h"
#include "graph/GraphManager.h"
#include "input/InputManager.h"
#include "util/Unique.h"
#include "game/Game.h"

namespace engine
{
	class Engine : public util::Unique<Engine>
	{
	public:
		explicit Engine(game::Game&, graph::Screen&, input::InputGetter&, audio::AudioPlayer&);
		~Engine();

		void Run();

	private:
		graph::GraphManager graphM;
		input::InputManager inputM;
		audio::AudioManager audioM;

		game::Game& game;
	};
}

#endif // _ENGINE_
