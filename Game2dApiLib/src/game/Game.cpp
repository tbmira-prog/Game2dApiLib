#include "Game.h"
using namespace game;

Game::Game() : Unique<Game>(), images(), controllables(), song(engine::audio::noSong), sounds(), quit(false), playingScene(false)
{}

Game::~Game()
{}

void Game::StartScene()
{
	LoadMedia();
	playingScene = true;
}

bool Game::PlayingScene() const
{
	return playingScene;
}

void Game::StopScene()
{
	playingScene = false;
}

void Game::FinishScene()
{
	FreeMedia();
}

void Game::QuitGame()
{
	playingScene = false;
	quit = true;
}

bool Game::Quit() const
{
	return quit;
}

void Game::Push(GameObject& object)
{
	images.push_back(object.image);
	controllables.push_back(object);
	sounds.push_back(object.soundEffect);
}