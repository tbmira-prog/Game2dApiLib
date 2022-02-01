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
	typedef std::vector<std::reference_wrapper<Image>> ImageVector; // UNDONE Vector � o conteiner mais otimizado para isto?

	class GraphManager : public Unique // UNDONE Pensar em como GraphManager poderia lidar com m�ltiplas janelas, ou se isso n�o ser� permitido
	{
	public:
		explicit GraphManager(Screen&);
		~GraphManager();

		void UpdateScreen(ImageVector images);

	private:
		Screen& screen;

		GraphManager(const GraphManager&) = delete;
		GraphManager& operator=(const GraphManager&) = delete;
	};
}

#endif // _GRAPH_MANAGER_