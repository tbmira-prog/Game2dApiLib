#ifndef _CONTROLLABLE_
#define _CONTROLLABLE_

#include <functional>
//#include <unordered_map>
#include <vector>

#include "engine/input/undoRedo/Command.h"
#include "Input.h"

namespace engine
{
	namespace input
	{
		class Controllable
		{
		public:
			Controllable() {}
			virtual ~Controllable() {}

			virtual void HandleInput(const Input& input) = 0;
		};
	}
}

#endif // _CONTROLLABLE_

//std::unordered_map < std::reference_wrapper<Input>, std::reference_wrapper<Command> > commandMap;