#ifndef _SCREEN_
#define _SCREEN_
 
#include "util/Unique.h"

namespace engine
{
	namespace graph
	{
		class Screen : public util::Unique<Screen>
		{
		public:
			Screen() {};
			virtual ~Screen() {};

			virtual void Clear() = 0;
			virtual void Update() = 0;

		private:
			Screen(const Screen&) = delete;
			Screen& operator=(const Screen&) = delete;
		};
	}
}

#endif // _SCREEN_