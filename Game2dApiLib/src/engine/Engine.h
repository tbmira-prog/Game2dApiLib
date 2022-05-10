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
	class Engine final : public util::Unique<Engine>
	{
	public:
		explicit Engine(game::Game&, graph::Screen&, input::Joystick&, audio::AudioPlayer&);
		~Engine();

		void Run();

	private:
		graph::GraphManager graphManager;
		input::InputManager inputManager;
		audio::AudioManager audioManager;

		game::Game& game;

	private:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
	};
}

#endif // _ENGINE_
