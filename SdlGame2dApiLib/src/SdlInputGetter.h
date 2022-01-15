#ifndef _SDL_INPUT_GETTER_
#define _SDL_INPUT_GETTER_

#include "InputGetter.h"

namespace input
{
	namespace sdl
	{
		class SdlInputGetter : public InputGetter // TODO Como implementar fun��es de pegar input? Como tratar eventos que n�o s�o inputs para o jogo mas s�o importantes (de forma autom�tica)? InputManager cria um objeto para lidar com eventos de fechamento?
		{
		public:
			SdlInputGetter() {};
			~SdlInputGetter() {};

			void GetInput(Input&); // TODO Usar apenas PullEvent ou usar PushEvent tamb�m de alguma maneira caso o evento n�o for ser tratado pelo jogo mas for um evento importante como o quit por exemplo?
			void WaitInput(Input& input, size_t timeOut_ms = 0); // TODO Usar apenas WaitEvent ou usar tamb�m PullEvent?
		};														// Como o usu�rio vai definir o timeout para o InputManager?
	}
}

#endif // _SDL_INPUT_GETTER_