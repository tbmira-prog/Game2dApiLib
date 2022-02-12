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
	inputGetter.WaitInput(input, timeOut_ms); // HACK Como fazer o usuário configurar o timeout?
}

//void InputManager::HandleInput(const Input& i, ControllableVector controllables)
//{
//	for (auto controllable : controllables)
//	{
//		controllable.HandleInput();
//		commandsExecuted.push(controllable.HandleInput()); // TO_DO Como colocar o comando dentro da lista?
//	}
//}

//void InputManager::Undo() // TO_DO Input managger deve ser responsável pelo Undo? Ou cada controllable?
//{
//	commandsExecuted.top().get().Undo();
//	commandsExecuted.pop();
//}