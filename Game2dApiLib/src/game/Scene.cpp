#include "Scene.h"
using namespace game;

Scene::Scene(Game& g) : objects(), playing(false), quit(false), next(this), game(g) {}

Scene::~Scene()
{
	objects.Clear();
}

void Scene::Start()
{
	LoadMedia();
	playing = true;
}

void Scene::ChangeSceneTo(Scene* pNewScene)
{
	next = pNewScene;
	playing = false;
}

void Scene::QuitGame()
{
	playing = false;
	quit = true;
}

void Scene::LoadMedia()
{
	//for (auto object : objects)
	//	object.LoadMedia();
}