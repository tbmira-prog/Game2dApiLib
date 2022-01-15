#ifndef _SDL_INPUT_GETTER_
#define _SDL_INPUT_GETTER_

#include "InputGetter.h"

namespace input
{
	namespace sdl
	{
		class SdlInputGetter : public InputGetter // TODO Como implementar funções de pegar input? Como tratar eventos que não são inputs para o jogo mas são importantes (de forma automática)? InputManager cria um objeto para lidar com eventos de fechamento?
		{
		public:
			SdlInputGetter() {};
			~SdlInputGetter() {};

			void GetInput(Input&); // TODO Usar apenas PullEvent ou usar PushEvent também de alguma maneira caso o evento não for ser tratado pelo jogo mas for um evento importante como o quit por exemplo?
			void WaitInput(Input& input, size_t timeOut_ms = 0); // TODO Usar apenas WaitEvent ou usar também PullEvent?
		};														// Como o usuário vai definir o timeout para o InputManager?
	}
}

#endif // _SDL_INPUT_GETTER_