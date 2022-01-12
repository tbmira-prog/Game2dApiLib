#include "KeyboardInput.h"
using namespace input::terminal;

KeyboardInput::KeyboardInput() : keyboardInput(' ') {}

KeyboardInput::KeyboardInput(char c) : keyboardInput(c) {}

KeyboardInput::~KeyboardInput() {};

bool KeyboardInput::operator==(const KeyboardInput& other) const
{
	return this->keyboardInput == other.keyboardInput;
}