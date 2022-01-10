#include "InputManager.h"
using namespace input;

InputManager::InputManager(InputGetter& newInputGetter) : Unique(), inputGetter(newInputGetter) {}

InputManager::~InputManager() {}

Input* InputManager::GetInput()
{
	return inputGetter->GetInput();
}

Input* InputManager::WaitInput()
{
	return inputGetter->WaitInput();
}

void InputManager::HandleInput(std::vector<Controllable> controllables, std::reference_wrapper <Input> input) const
{
	for (auto i = controllables.begin(); i != controllables.end(); i++)
		i->HandleInput(*input);
}
