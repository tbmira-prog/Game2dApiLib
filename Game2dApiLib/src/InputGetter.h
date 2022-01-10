#ifndef _INPUT_GETTER_
#define _INPUT_GETTER_

#include "Input.h"

namespace input
{
	class InputGetter : public Unique // Unique?
	{
	public:
		InputGetter() {};
		virtual ~InputGetter() {};

		virtual Input* GetInput() = 0; // retorna input ou, recebe input e altera ele
		virtual Input* WaitInput() = 0; // retorna input ou, recebe input e altera ele
										// Retornando um ponteiro ia precisar ficar alocando memória dinamicamente
	};
}

#endif // _INPUT_GETTER_