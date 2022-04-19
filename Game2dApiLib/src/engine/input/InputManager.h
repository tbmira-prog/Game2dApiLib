#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include <functional>
#include <memory>
#include <stack>

//#include "Command.h" TO_DO Tirar command daqui, pois apenas o jogo irá usar essa classe se desejar
#include "Controllable.h"
#include "Input.h"
#include "InputGetter.h"
#include "util/Unique.h"

// TO_DO Ver construtores que precisam de explicit
// Sistema de Undo e Redo é de responsabilidade de cada jogo implementar
// Game engine controla o loop. Programador irá interagir com o loop através da função HandleInput de seus controllables

namespace engine
{
	namespace input
	{
		typedef std::vector< std::reference_wrapper<Controllable>> ControllableVector;

		class InputManager : public Unique<InputManager> // HACK Planejar tratamento de eventos que não são inputs, por exemplo fechar programa
		{
		public:
			InputManager(InputGetter&);
			~InputManager();

			inline void GetInput(Input&);
			inline void WaitInput(Input&, size_t timeOut_ms = 0);

			void HandleInput(const Input&, ControllableVector); // TO_DO Escrever HandleInput e também typedef ControllableVector

		private:
			InputGetter& inputGetter;
		};
	}
}

#endif // _INPUT_MANAGER_