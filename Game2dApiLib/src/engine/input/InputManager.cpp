#include "InputManager.h"
using namespace engine::input;

InputManager::InputManager(InputGetter& newInputGetter) : Unique<InputManager>(), inputGetter(newInputGetter) {}

InputManager::~InputManager() {}

void InputManager::GetInput(size_t timeOut_ms)
{
	inputGetter.GetInput(timeOut_ms);
}

void InputManager::HandleInput(ControllableVector controllables) const
{
	for (auto controllable : controllables)
	{
		controllable.get().HandleInput(inputGetter.Input());
	}
}
