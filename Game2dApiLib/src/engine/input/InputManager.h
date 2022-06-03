#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include <functional>
#include <memory>
#include <stack>

#include "Controllable.h"
#include "Input.h"
#include "Joystick.h"
#include "util/Unique.h"

namespace engine
{
	namespace input
	{
		typedef std::vector< std::reference_wrapper<Controllable>> ControllableVector;

		class InputManager final : public util::Unique<InputManager>
		{
		public:
			explicit InputManager(Joystick&);
			~InputManager();

			void GetInput();

			void HandleInput(ControllableVector&) const;

		private:
			Joystick& inputGetter;

			InputManager(const InputManager&) = delete;
			InputManager& operator=(const InputManager&) = delete;
		};
	}
}

#endif // _INPUT_MANAGER_