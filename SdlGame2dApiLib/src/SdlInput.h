#ifndef _SDL_INPUT_
#define _SDL_INPUT_

#include <SDL.h> // https://wiki.libsdl.org/SDL_Event

#include "Input.h"

namespace input
{
	namespace sdl
	{
		class SdlInput : public Input
		{
		public:
			SdlInput() {};
			virtual ~SdlInput() {}; // Virtual?

			std::size_t Hash() const; // TODO Implementar hash retornando o valor de SDL_EVENT_TYPE
			bool operator==(const Input&) const override;

		private:
			SDL_Event sdlEvent;
		};
	}
}
#endif // _SDL_INPUT_
