#include "InputManager.h"
using namespace input;

InputManager::InputManager(InputGetter& newInputGetter) : Unique(), inputGetter(&newInputGetter) {}

InputManager::~InputManager() {}

Input* InputManager::GetInput()
{
	return inputGetter->GetInput();
}

Input* InputManager::WaitInput()
{
	return inputGetter->WaitInput();
}