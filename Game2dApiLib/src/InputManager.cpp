#include "InputManager.h"
using namespace input;

InputManager::InputManager(InputGetter& newInputGetter) : Unique(), inputGetter(&newInputGetter) {}

InputManager::~InputManager() {}

void InputManager::GetInput(Input& input)
{
	inputGetter->GetInput(input);
}

void InputManager::WaitInput(Input& input)
{
	inputGetter->WaitInput(input); // HACK Como fazer o usu�rio configurar o timeout?
}