#include "Engine.h"
using namespace engine;

#include "audio/AudioPlayer.h"
#include "graph/Screen.h"
#include "input/InputGetter.h"
#include "game/Game.h"

Engine::Engine(game::Game& newGame, graph::Screen& screen, input::InputGetter& inputGetter, audio::AudioPlayer& audioPlayer) :
	Unique<Engine>(), game(newGame), graphManager(screen), inputManager(inputGetter), audioManager(audioPlayer)
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
			{ // TODO Cada biblioteca deve implementar as funções para lidar com Quit, Resize, etc. Por exemplo, SdlGame já coloca um controllable no vetor para tratar estes eventos
				inputManager.GetInput();
				inputManager.HandleInput(game.Controllables());
				graphManager.UpdateScreen(game.Images());
				audioManager.PlaySoundEffects(game.Sounds());
				audioManager.ControlMusic(game.CurrentSong(), game.SongAction());
			}

			game.FinishScene();
		}
		catch (...)
		{
			break;
		}
	}
}
