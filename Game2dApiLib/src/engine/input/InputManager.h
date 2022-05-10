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

		class InputManager final : public util::Unique<InputManager> // HACK Planejar tratamento de eventos que não são inputs, por exemplo fechar programa
		{
		public:
			explicit InputManager(Joystick&);
			~InputManager();

			inline void GetInput(size_t timeOut_ms = 0);

			void HandleInput(ControllableVector) const;

		private:
			Joystick& inputGetter;

			InputManager(const InputManager&) = delete;
			InputManager& operator=(const InputManager&) = delete;
		};
	}
}

#endif // _INPUT_MANAGER_