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

namespace engine
{
	namespace input
	{
		typedef std::vector< std::reference_wrapper<Controllable>> ControllableVector;

		class InputManager final : public util::Unique<InputManager> // HACK Planejar tratamento de eventos que não são inputs, por exemplo fechar programa
		{
		public:
			explicit InputManager(InputGetter&);
			~InputManager();

			inline void GetInput(size_t timeOut_ms = 0);

			void HandleInput(ControllableVector) const;

		private:
			InputGetter& inputGetter;

			InputManager(const InputManager&) = delete;
			InputManager& operator=(const InputManager&) = delete;
		};
	}
}

#endif // _INPUT_MANAGER_