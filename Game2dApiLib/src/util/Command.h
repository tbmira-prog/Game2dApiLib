#ifndef _COMMAND_
#define _COMMAND_

namespace input
{
	class Command // TODO Pensar sobre comportamento quanto a c�pia, atribui��o, ... de objetos desta classe
	{
	public:
		Command() {};
		virtual ~Command() {};

		virtual void Execute() = 0;
		virtual void Undo() = 0;
	};
}

#endif _COMMAND_