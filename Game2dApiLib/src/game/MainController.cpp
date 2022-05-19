#include "MainController.h"
using namespace game;

MainController::MainController(Scene* s) : Controller(), pScene(s) {}

MainController::~MainController() {}

void MainController::LoadMedia() {}

void MainController::HandleInput(const engine::input::Input& i)
{
	if (i.Quit())
		pScene->QuitGame();
	else if (i.Undo())
		;
	else if (i.Redo())
		;
}