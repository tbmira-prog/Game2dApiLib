#include "InputManager.h"
using namespace input;

InputManager::InputManager(InputGetter& newInputGetter) : Unique<InputManager>(), inputGetter(newInputGetter) {}

InputManager::~InputManager() {}

void InputManager::GetInput(Input& input)
{
	inputGetter.GetInput(input);
}

void InputManager::WaitInput(Input& input, size_t timeOut_ms)
{
	inputGetter.WaitInput(input, timeOut_ms);
}

void InputManager::HandleInput(const std::reference_wrapper<Input> i, ControllableVector controllables)
{
	for (auto controllable : controllables)
	{
		controllable.get().HandleInput(i);
		//commandsExecuted.push(controllable.HandleInput()); // TO_DO Como colocar o comando dentro da lista?
	}
}

//void InputManager::Undo() // TO_DO Input managger deve ser responsável pelo Undo? Ou cada controllable?
//{
//	commandsExecuted.top().get().Undo();
//	commandsExecuted.pop();
//}