#ifndef _INPUT_
#define _INPUT_

namespace input
{
	class Input // HACK Hash e Polimorfismo, como usar essa classe como uma interface e tamb�m como chave de um unorded_map?
	{
	public:
		Input() {};
		virtual ~Input() {};

		virtual bool operator==(const Input&) const = 0; // TO_DO Declarar fun��o fora da classe? Livro de C++ em um dos cap�tulos l� fala disso
		//virtual std::size_t Hash() const = 0;
	protected:

	};
}

#endif // _INPUT_