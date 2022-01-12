#include "KeyboardInput.h"
using namespace input::terminal;

KeyboardInput::KeyboardInput() : Input(), keyboardInput(' ') {}

KeyboardInput::KeyboardInput(char c) : Input(), keyboardInput(c) {}

KeyboardInput::~KeyboardInput() {};

bool KeyboardInput::operator==(const KeyboardInput& other) const
{
	return this->keyboardInput == other.keyboardInput;
}