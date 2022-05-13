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

			Input(const Input&) = default; // TO_DO Classes filhas devem chamar este construtor na lista de inicialização de seus construtores de cópia
			Input& operator=(const Input&) = default;

			virtual bool operator==(const Input&) const = 0; // UNDONE Declarar função fora da classe? Livro de C++ em um dos capítulos lá fala disso

			virtual bool Quit() const = 0; // HACK Criar classes Controller que irá checar estas funções
			virtual bool Undo() const { return false; }
			virtual bool Redo() const { return false; }
		};
	}
}

#endif // _INPUT_