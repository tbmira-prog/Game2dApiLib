#include "Joystick.h"
using namespace engine::input;

Joystick::Joystick(engine::input::Input& i, InputGetMode newMode) : Unique<Joystick>(), input(i), mode(newMode) {}

Joystick::~Joystick() {}

void Joystick::GetInput(size_t timeOut_ms)
{
	switch (mode)
	{
	case InputGetMode::POOL_INPUT:
		PoolInput();
		break;
	case InputGetMode::WAIT_INPUT:
		WaitInput(timeOut_ms);
		break;
	default:
		PoolInput();
	}
}

const Input& Joystick::Input() const
{
	return input;
}

void Joystick::ChangeMode(InputGetMode newMode)
{
	mode = newMode;
}