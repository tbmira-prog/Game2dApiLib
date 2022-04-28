#ifndef _COMMAND_
#define _COMMAND_

namespace input
{
	class Command // HACK Pensar sobre comportamento quanto a cópia, atribuição, ... de objetos desta classe
	{
	public:
		Command() {};
		virtual ~Command() {};

		virtual void Execute() = 0;
		virtual void Undo() = 0;
	};
}

#endif _COMMAND_