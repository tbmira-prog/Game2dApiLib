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
		typedef std::vector<std::reference_wrapper<Image>> ImageVector; // UNDONE Vector � o conteiner mais otimizado para isto?

		class GraphManager final : public util::Unique<GraphManager>
		{
		public:
			explicit GraphManager(Screen&);
			~GraphManager();

			void UpdateScreen(ImageVector images);

		private:
			Screen& screen; // HACK Usar shared_ptr ao inv�s de & ???

			GraphManager(const GraphManager&) = delete;
			GraphManager& operator=(const GraphManager&) = delete;
		};
	}
}

#endif // _GRAPH_MANAGER_