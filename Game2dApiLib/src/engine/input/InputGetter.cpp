#include "InputGetter.h"
using namespace engine::input;

InputGetter::InputGetter(engine::input::Input& i, InputGetMode newMode) : Unique<InputGetter>(), input(i), mode(newMode) {}

InputGetter::~InputGetter() {}

void InputGetter::GetInput(size_t timeOut_ms)
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
		WaitInput(timeOut_ms);
	}
}

const Input& InputGetter::Input() const
{
	return input;
}

void InputGetter::ChangeMode(InputGetMode newMode)
{
	mode = newMode;
}