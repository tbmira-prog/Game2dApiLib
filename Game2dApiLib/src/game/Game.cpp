#include "Game.h"
using namespace game;

Game::Game(Scene* pFirstScene) : Unique<Game>(), pCurrentScene(pFirstScene)
{}

Game::~Game()
{}


void Game::ChangeScene()
{
	if (!pCurrentScene->Playing() && pCurrentScene->next != pCurrentScene)
	{
		Scene* pNewScene = pCurrentScene->next;
		delete pCurrentScene;
		pCurrentScene = pNewScene;
	}
}