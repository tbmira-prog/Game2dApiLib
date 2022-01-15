#ifndef _INPUT_GETTER_
#define _INPUT_GETTER_

#include "Input.h"

namespace input
{
	class InputGetter // TODO Unique?
	{
	public:
		InputGetter() {};
		virtual ~InputGetter() {};

		virtual void GetInput(Input&) = 0;
		virtual void WaitInput(Input& input, size_t timeOut_ms) = 0;
	};
}

#endif // _INPUT_GETTER_