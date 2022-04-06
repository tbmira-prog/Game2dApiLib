#ifndef _SDL_INPUT_
#define _SDL_INPUT_

#include <SDL.h> // https://wiki.libsdl.org/SDL_Event

#include "Input.h"

namespace input
{
	namespace sdl
	{
		class SdlInput : public Input // TO_DO Trocar nome, não precisa do Sdl pois já está no namespace sdl
		{
			friend class InputGetter;

		public:
			SdlInput() : sdlEvent() {};
			//Input(); // HACK Construtor para criar inputs mais facilmente para serem comparados

			virtual ~SdlInput() {}; // Virtual?

			//std::size_t Hash() const; // TO_DO Implementar hash retornando o valor de SDL_EVENT_TYPE
			bool operator==(const input::Input&) const override; // HACK Criar outros comparadores (SDL_Event, etc.)

		private:
			SDL_Event sdlEvent;
		};
	}
}
#endif // _SDL_INPUT_
