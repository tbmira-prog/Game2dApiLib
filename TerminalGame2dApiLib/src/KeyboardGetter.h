#ifndef _KEYBOARD_GETTER_
#define _KEYBOARD_GETTER_

#include "InputGetter.h"

namespace input
{
	namespace terminal
	{
		class KeyboardGetter : public InputGetter
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
