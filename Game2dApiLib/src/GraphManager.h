#ifndef _GRAPH_MANAGER_
#define _GRAPH_MANAGER_

#include <functional>
#include <memory>
#include <vector>

#include "Image.h"
#include "Screen.h"
#include "Unique.h"

namespace graph
{
	class GraphManager : public Unique
	{
	public:
		GraphManager(Screen&);
		~GraphManager();

		void UpdateScreen(const std::vector<std::reference_wrapper<Image>>& images);

	private:
		std::unique_ptr<Screen> screen;

	private:
		GraphManager(const GraphManager&);
		GraphManager& operator=(const GraphManager&);
	};
}

#endif // _GRAPH_MANAGER_