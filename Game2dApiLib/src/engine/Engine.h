#ifndef _ENGINE_
#define _ENGINE_

#include <functional>
#include <memory>

#include "game/Game.h"

#include "audio/AudioManager.h"
#include "graph/GraphManager.h"
#include "input/InputManager.h"

#include "util/Unique.h"

namespace engine
{
	class Engine : public util::Unique<Engine>
	{
	public:
		explicit Engine(game::Game&, graph::Screen&, input::Joystick&, audio::AudioPlayer&);
		~Engine();

		void Run();
		
		static const graph::Screen& Screen();

	private:
		graph::GraphManager graphManager;
		input::InputManager inputManager;
		audio::AudioManager audioManager;

		game::Game& game;

		static graph::Screen* pScreen;

	private:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
	};

}

#endif // _ENGINE_
