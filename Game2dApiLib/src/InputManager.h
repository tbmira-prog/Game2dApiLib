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
	class InputManager : public Unique // HACK Planejar tratamento de eventos que não são inputs, por exemplo fechar programa
	{
	public:
		InputManager(InputGetter&);
		~InputManager();

		inline void GetInput(Input&);
		inline void WaitInput(Input&);

		//void HandleInput(const Input&, std::vector<Controllable>); // TODO Escrever HandleInput e também typedef ControllableVector

	private:
		std::unique_ptr <InputGetter> inputGetter;
	};
}

#endif // _INPUT_MANAGER_