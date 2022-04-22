#ifndef _GRAPH_MANAGER_
#define _GRAPH_MANAGER_

#include <functional>
#include <memory>
#include <vector>

#include "Image.h"
#include "Screen.h"
#include "util/Unique.h"

namespace engine
{
	namespace graph
	{
		typedef std::vector<std::reference_wrapper<Image>> ImageVector; // UNDONE Vector é o conteiner mais otimizado para isto?

		class GraphManager : public util::Unique<GraphManager> // UNDONE Pensar em como GraphManager poderia lidar com múltiplas janelas, ou se isso não será permitido
		{
		public:
			explicit GraphManager(Screen&);
			~GraphManager();

			void UpdateScreen(ImageVector images);

		private:
			Screen& screen; // TODO Usar shared_ptr ao invés de & ???

			GraphManager(const GraphManager&) = delete;
			GraphManager& operator=(const GraphManager&) = delete;
		};
	}
}

#endif // _GRAPH_MANAGER_