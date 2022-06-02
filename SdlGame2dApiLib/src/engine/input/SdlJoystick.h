#ifndef _SDL_INPUT_GETTER_
#define _SDL_INPUT_GETTER_

#include <cstdlib>

#include "SDL.h"

#include "engine/input/Joystick.h"
#include "SdlInput.h"

namespace engine
{
	namespace input
	{
		namespace sdl
		{
			class SdlJoystick : public Joystick // TO_DO Como implementar funções de pegar input? Como tratar eventos que não são inputs para o jogo mas são importantes (de forma automática)? InputManager cria um objeto para lidar com eventos de fechamento?
			{
			public:
				SdlJoystick(InputGetMode newMode = InputGetMode::POLL_INPUT, size_t timeOut_ms = 0);
				~SdlJoystick();

				void PollInput() override; // TO_DO Usar apenas PullEvent ou usar PushEvent também de alguma maneira caso o evento não for ser tratado pelo jogo mas for um evento importante como o quit por exemplo?
				void WaitInput(size_t timeOut_ms = 0) override; // TO_DO Usar apenas WaitEvent ou usar também PullEvent?
																			 // Como o usuário vai definir o timeout para o InputManager?
			private:
				SdlInput sdlInput;
			};
		}
	}
}

#endif // _SDL_INPUT_GETTER_