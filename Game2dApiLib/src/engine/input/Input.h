#ifndef _INPUT_
#define _INPUT_

namespace engine
{
	namespace input
	{
		class Input // HACK Hash e Polimorfismo, como usar essa classe como uma interface e também como chave de um unorded_map?
		{
		public:
			Input() {};
			virtual ~Input() {};

			virtual bool operator==(const Input&) const = 0; // TO_DO Declarar função fora da classe? Livro de C++ em um dos capítulos lá fala disso
			//virtual std::size_t Hash() const = 0;
			virtual bool Quit() = 0;

		};
	}
}

#endif // _INPUT_