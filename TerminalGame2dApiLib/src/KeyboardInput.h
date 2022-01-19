#ifndef _KEYBOARD_INPUT_
#define _KEYBOARD_INPUT_

#include "Input.h"

namespace input
{
	namespace terminal
	{
		class KeyboardInput : public Input
		{
		public:
			KeyboardInput();
			KeyboardInput(char);

			~KeyboardInput();

			bool operator==(const Input&) const override;

		//private:
			char keyboardInput;
		};
	}
}

#endif // _KEYBOARD_INPUT_