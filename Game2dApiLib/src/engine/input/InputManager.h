#ifndef _INPUT_MANAGER_
#define _INPUT_MANAGER_

#include <functional>
#include <memory>
#include <stack>

//#include "Command.h" TO_DO Tirar command daqui, pois apenas o jogo ir� usar essa classe se desejar
#include "Controllable.h"
#include "Input.h"
#include "InputGetter.h"
#include "util/Unique.h"

// TO_DO Ver construtores que precisam de explicit

namespace engine
{
	namespace input
	{
		typedef std::vector< std::reference_wrapper<Controllable>> ControllableVector;

		class InputManager : public util::Unique<InputManager> // HACK Planejar tratamento de eventos que n�o s�o inputs, por exemplo fechar programa
		{
		public:
			InputManager(InputGetter&);
			~InputManager();

			inline void GetInput(size_t timeOut_ms = 0);

			void HandleInput(ControllableVector) const; // TO_DO Escrever HandleInput e tamb�m typedef ControllableVector

		private:
			InputGetter& inputGetter;
		};
	}
}

#endif // _INPUT_MANAGER_