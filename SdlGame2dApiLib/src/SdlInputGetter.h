#ifndef _SDL_INPUT_GETTER_
#define _SDL_INPUT_GETTER_

#include "InputGetter.h"

namespace input
{
	namespace sdl
	{
		class SdlInputGetter : public InputGetter // TODO Unique?
		{
		public:
			SdlInputGetter() {};
			~SdlInputGetter() {};

			void GetInput(Input&);
			void WaitInput(Input& input, size_t timeOut_ms = 0);
		};
	}
}

#endif // _SDL_INPUT_GETTER_