#include "KeyboardInput.h"
using namespace input::terminal;

KeyboardInput::KeyboardInput() : Input(), keyboardInput(' ') {}

KeyboardInput::KeyboardInput(char c) : Input(), keyboardInput(c) {}

KeyboardInput::~KeyboardInput() {};

bool KeyboardInput::operator==(const Input& other) const
{
	const KeyboardInput* charInput = dynamic_cast<const KeyboardInput*>(&other);
	if (charInput)
		return this->keyboardInput == charInput->keyboardInput;
	else
		return false;
}