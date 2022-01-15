#ifndef _INPUT_
#define _INPUT_

namespace input
{
	class Input
	{
	public:
		Input();
		virtual ~Input();

		virtual bool operator==(const Input&) const = 0; // Declarar fun��o fora da classe? Livro de C++ em um dos cap�tulos l� fala disso
		virtual std::size_t Hash() const = 0;
	protected:

	};
}

#endif // _INPUT_