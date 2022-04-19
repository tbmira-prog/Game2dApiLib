#include "InputManager.h"
using namespace engine::input;

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

void InputManager::HandleInput(const Input& i, ControllableVector controllables)
{
	for (auto controllable : controllables)
	{
		controllable.get().HandleInput(i);
	}
}
