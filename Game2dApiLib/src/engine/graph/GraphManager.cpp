#include "GraphManager.h"
using namespace engine::graph;

GraphManager::GraphManager(Screen& newScreen) : util::Unique<GraphManager>(), screen(newScreen) {}

GraphManager::~GraphManager() {}

void GraphManager::UpdateScreen(ImageVector images)
{
	screen.Clear();

	for (auto image : images)
		image.get().Print(screen);

	screen.Update();
}