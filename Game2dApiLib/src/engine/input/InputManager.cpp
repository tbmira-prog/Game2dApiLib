#include "InputManager.h"
using namespace engine::input;

InputManager::InputManager(Joystick& newJoystick) : Unique<InputManager>(), inputGetter(newJoystick) {}

InputManager::~InputManager() {}

void InputManager::GetInput()
{
	inputGetter.GetInput();
}

void InputManager::HandleInput(ControllableVector& controllables) const
{
	for (auto controllable : controllables)
		controllable.get().HandleInput(inputGetter.Input()); // TO_DO Voltar Input para algum valor padrão? Se ele reter o último valor pode causar erros no modo poll
}
