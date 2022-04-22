#include "Game.h"
using namespace game;

Game::Game() : Unique<Game>(), images(), controllables(), musics(), sounds(), quit(false), playingScene(false)
{}

Game::~Game()
{}

void Game::StartScene()
{
	LoadMedia();
	playingScene = true;
}

bool Game::PlayingScene()
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

void Gamee::QuitGame()
{
	playingScene = false;
	quit = true;
}

bool Game::Quit()
{
	return quit;
}

void Game::Push(GameObject& object)
{
	images.push_back(object.image);
	controllables.push_back(object);
}