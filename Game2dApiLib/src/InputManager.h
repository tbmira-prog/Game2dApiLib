#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include <functional>
#include <memory>

#include "Controllable.h"
#include "Input.h"
#include "InputGetter.h"
#include "Unique.h"

namespace input
{
	class InputManager : public Unique
	{
	public:
		InputManager(InputGetter&);
		~InputManager();

		inline Input* GetInput();
		inline Input* WaitInput();

		virtual void HandleInput(std::vector<Controllable> controllables, std::reference_wrapper <Input> input) const;

	private:
		std::unique_ptr <InputGetter> inputGetter;
	};
}

#endif // _INPUT_MANAGER_