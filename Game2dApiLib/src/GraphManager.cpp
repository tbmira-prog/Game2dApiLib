#include "GraphManager.h"
using namespace graph;

GraphManager::GraphManager(Screen& newScreen) : Unique(), screen(newScreen) {}

GraphManager::~GraphManager() {}

void GraphManager::UpdateScreen(ImageVector images)
{
	screen.Clear();

	for (auto image = images.cbegin(); image != images.cend(); image++)
		image->get().Print(screen);

	screen.Update();
}