#include "GraphManager.h"
using namespace graph;

GraphManager::GraphManager(Screen& newScreen) : Unique(), screen(&newScreen) {}

GraphManager::~GraphManager() {}

void GraphManager::UpdateScreen(std::vector<std::reference_wrapper<Image>> images)
{
	screen->Clear();

	for (auto image = images.cbegin(); image != images.cend(); image++)
		image->get().Print(*screen);
}