#include "Engine.h"
using namespace engine;

Engine::Engine(game::Game& newGame, graph::Screen& screen, input::InputGetter& inputGetter, audio::AudioPlayer& audioPlayer) :
	Unique<Engine>(), game(newGame), graphM(screen), inputM(inputGetter), audioM(audioPlayer), quit(false), playing(false)
{}

Engine::~Engine() {}

void Engine::Run()
{
	quit = false;
	while (!quit)
	{
		game.LoadMedia();
		
		playing = true;
		while (playing)
		{
			inputM.GetInput(input);
			if (!input.Quit())
			{
				inputM.HandleInput(input, game.Controllables());
				graphM.UpdateScreen(game.Images());
				audioM.PlaySoundEffects(game.Sounds()); // HACK Como controlar as músicas durante o gameplay?
			}
			else
				Quit();
		}

		game.FreeMedia();
	}
}

void Engine::Quit()
{
	playing = false;
	quit = true;
}

void Engine::StopPlaying()
{
	playing = false;
}