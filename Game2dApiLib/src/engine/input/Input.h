#ifndef _INPUT_
#define _INPUT_

namespace engine
{
	namespace input
	{
		class Input // HACK Hash e Polimorfismo, como usar essa classe como uma interface e tamb�m como chave de um unorded_map?
		{
		public:
			Input() {};
			virtual ~Input() {};

			Input(const Input&) = default; // TO_DO Classes filhas devem chamar este construtor na lista de inicializa��o de seus construtores de c�pia
			Input& operator=(const Input&) = delete;


			virtual bool operator==(const Input&) const = 0; // TO_DO Declarar fun��o fora da classe? Livro de C++ em um dos cap�tulos l� fala disso
			//virtual std::size_t Hash() const = 0;
			virtual bool Quit() const = 0;

		};
	}
}

#endif // _INPUT_