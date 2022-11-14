#include "Engine.h"
using namespace engine;
#include <iostream>

graph::Screen* Engine::pScreen = nullptr;

Engine::Engine(graph::Screen& screen, input::Joystick& inputGetter, audio::AudioPlayer& audioPlayer) :
	Unique<Engine>(), graphManager(screen), inputManager(inputGetter), audioManager(audioPlayer)
{
	pScreen = &screen;
}

Engine::~Engine() {}

void Engine::Run(game::Game& game)
{
	while (!game.pCurrentScene->Quit()) // HACK Melhorar logs
	{
		try
		{
			game.pCurrentScene->Start();

			while (game.pCurrentScene->Playing())
			{ // TODO Cada biblioteca deve implementar as funções para lidar com Quit, Resize, etc. Por exemplo, SdlGame já coloca um controllable no vetor para tratar estes eventos
				inputManager.GetInput();
				inputManager.HandleInput(game.pCurrentScene->Controllables());
				game.pCurrentScene->Logic();
				graphManager.UpdateScreen(game.pCurrentScene->Images());
				if (!audioManager.Muted())
				{
					audioManager.PlaySoundEffects(game.pCurrentScene->Sounds());
					audioManager.ControlMusic(game.pCurrentScene->CurrentSong(), game.pCurrentScene->SongAction());
				}
			}

			game.ChangeScene();
		}
		catch ( const std::exception& e )
		{
			std::cerr << e.what() << std::endl;
			//std::cin.get();
			break;
		}
	}
}

const graph::Screen& Engine::Screen()
{
	return *pScreen;
}