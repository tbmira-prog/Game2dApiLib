#ifndef _INPUT_GETTER_
#define _INPUT_GETTER_

#include "Input.h"

namespace engine
{
	namespace input
	{
		class InputGetter // UNDONE Planejar se classes como InputGetter, AudioPlayer e Screen serão únicas ou não
		{				 // Únicas: InputGetter e AudioPlayer. Múltiplas: Screen
		public:
			InputGetter() {};
			virtual ~InputGetter() {};

			virtual void GetInput(Input&) = 0;
			virtual void WaitInput(Input& input, size_t timeOut_ms) = 0;
		};
	}
}

#endif // _INPUT_GETTER_