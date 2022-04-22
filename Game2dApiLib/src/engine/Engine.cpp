#include "Engine.h"
using namespace engine;

#include "audio/AudioPlayer.h"
#include "graph/Screen.h"
#include "input/InputGetter.h"
#include "game/Game.h"

Engine::Engine(game::Game& newGame, graph::Screen& screen, input::InputGetter& inputGetter, audio::AudioPlayer& audioPlayer) :
	Unique<Engine>(), game(newGame), graphM(screen), inputM(inputGetter), audioM(audioPlayer)
{}

Engine::~Engine() {}

void Engine::Run()
{
	while (!game.Quit()) // HACK Exception safety: try and catch
	{
		try
		{
			game.StartScene();

			while (game.PlayingScene())
			{
				inputM.GetInput();
				inputM.HandleInput(game.Controllables());
				graphM.UpdateScreen(game.Images());
				audioM.PlaySoundEffects(game.Sounds()); // HACK Como controlar as músicas durante o gameplay?
			}

			game.FinishScene();
		}
		catch (...)
		{
			break;
		}
	}
}
