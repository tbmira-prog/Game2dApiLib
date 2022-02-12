#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include <functional>
#include <memory>
#include <stack>

#include "Command.h"
#include "Controllable.h"
#include "Input.h"
#include "InputGetter.h"
#include "Unique.h"

// TO_DO Ver construtores que precisam de explicit

namespace input
{
	//typedef std::vector<Controllable> ControllableVector; // TO_DO Controllable
	//typedef std::stack<std::reference_wrapper<Command>> CommandStack;

	class InputManager : public Unique<InputManager> // HACK Planejar tratamento de eventos que não são inputs, por exemplo fechar programa
	{
	public:
		InputManager(InputGetter&);
		~InputManager();

		inline void GetInput(Input&);
		inline void WaitInput(Input&, size_t timeOut_ms = 0);

//		void HandleInput(const Input&, ControllableVector ); // TO_DO Escrever HandleInput e também typedef ControllableVector
		void Undo();

	private:
		InputGetter& inputGetter;
		//CommandStack commandsExecuted;
	};
}

#endif // _INPUT_MANAGER_