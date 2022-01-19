#include <iostream>

#include "KeyboardGetter.h"
#include "KeyboardInput.h"
using namespace input::terminal;

void KeyboardGetter::GetInput(Input& input)
{
	KeyboardInput* charInput = dynamic_cast<KeyboardInput*>(&input);
	if(charInput)
		std::cin >> charInput->keyboardInput;
}

void KeyboardGetter::WaitInput(Input& input, size_t timeOut_ms)
{
	KeyboardInput* charInput = dynamic_cast<KeyboardInput*>(&input);
	if (charInput)
		std::cin >> charInput->keyboardInput;
}