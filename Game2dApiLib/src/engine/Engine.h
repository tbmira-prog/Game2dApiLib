#ifndef _ENGINE_
#define _ENGINE_

#include <functional>
#include <memory>

#include "audio/AudioManager.h"
#include "audio/AudioPlayer.h"
#include "graph/GraphManager.h"
#include "graph/Screen.h"
#include "input/InputGetter.h"
#include "input/InputManager.h"
#include "util/Unique.h"
#include "game/Game.h"

namespace engine
{
	class Engine : public Unique<Engine>
	{
	public:
		explicit Engine(game::Game&, graph::Screen&, input::InputGetter&, audio::AudioPlayer&);
		~Engine();

		void Run();

		inline void Quit(); // HACK Como um Game vai chamar estas fun��es Quit e StopPlaying? Engine tem que ser capaz de chamar Quit automaticamente
		inline void StopPlaying(); // HACK Como um Game ir� chamar esta fun��o para encerrar uma cena?

	private:
		graph::GraphManager graphM;
		input::InputManager inputM;
		audio::AudioManager audioM;

	private:
		game::Game& game;

		//input::Input& input;

		bool quit, playing;
	};
}

#endif // _ENGINE_
