#include "Scene.h"
#include "MainController.h"
using namespace game;

Scene::Scene() : objects(), playing(false), quit(false), next(this)
{
	mainController.SetScene(this);
	objects.Push(mainController);
}

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
	//for (auto object : objects) // HACK Iterar nos GameObjects
	//	object.LoadMedia();
}