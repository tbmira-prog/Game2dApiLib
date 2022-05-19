#ifndef _KEYBOARD_GETTER_
#define _KEYBOARD_GETTER_

#include "engine/input/Joystick.h"

namespace input
{
	namespace terminal
	{
		class KeyboardGetter : public Joystick
		{
		public:
			KeyboardGetter() {};
			~KeyboardGetter() {};

			void GetInput(Input&) override;
			void WaitInput(Input& input, size_t timeOut_ms) override;
		};
	}
}

#endif // _KEYBOARD_GETTER_
