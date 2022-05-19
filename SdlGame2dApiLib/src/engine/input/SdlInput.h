#ifndef _SDL_INPUT_
#define _SDL_INPUT_

#include <SDL.h> // https://wiki.libsdl.org/SDL_Event

#include "engine/input/Input.h"

namespace engine
{
	namespace input
	{
		namespace sdl
		{
			class SdlInput : public Input // TO_DO Trocar nome, não precisa do Sdl pois já está no namespace sdl
			{
				friend class SdlJoystick;

			public:
				SdlInput();
				SdlInput(const SDL_Event&);
				SdlInput(const SDL_EventType& type, const SDL_Keycode& sym);
				SdlInput(const SDL_EventType& type, Uint8 button, Uint8 clicks);
				SdlInput(const SDL_EventType& type, Uint32 direction);

				virtual ~SdlInput();

				bool operator==(const input::Input&) const override; // HACK Criar outros comparadores (SDL_Event, etc.)
				bool operator==(const SDL_Event&) const;
				bool operator==(const SDL_EventType&) const;

				const SDL_Event& Event() const { return sdlEvent; }

				bool Quit() const override;
				bool Undo() const override;
				bool Redo() const override;

			private:
				SDL_Event sdlEvent;
			};
		}
	}
}

#endif // _SDL_INPUT_
