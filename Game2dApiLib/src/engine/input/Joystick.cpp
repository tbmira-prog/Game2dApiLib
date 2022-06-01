#include "Joystick.h"
using namespace engine::input;

Joystick::Joystick(engine::input::Input& i, const InputGetMode& newMode, size_t timeOut_ms) :
	Unique<Joystick>(), input(i), mode(newMode), timeOut_ms(timeOut_ms)
{}

Joystick::~Joystick() {}

void Joystick::GetInput()
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