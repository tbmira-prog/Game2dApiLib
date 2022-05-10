#ifndef _INPUT_
#define _INPUT_

namespace engine
{
	namespace input
	{
		class Input
		{
		public:
			Input() {};
			virtual ~Input() {};

			Input(const Input&) = default; // TO_DO Classes filhas devem chamar este construtor na lista de inicializa��o de seus construtores de c�pia
			Input& operator=(const Input&) = delete;


			virtual bool operator==(const Input&) const = 0; // UNDONE Declarar fun��o fora da classe? Livro de C++ em um dos cap�tulos l� fala disso

			virtual bool Quit() = 0; // HACK Criar classes Controller que ir� checar estas fun��es
			virtual bool Undo() { return false; }
			virtual bool Redo() { return false; }
		};
	}
}

#endif // _INPUT_