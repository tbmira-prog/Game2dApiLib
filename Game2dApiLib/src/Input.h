#ifndef _INPUT_
#define _INPUT_

namespace input
{
	class Input
	{
	public:
		Input();
		virtual ~Input();

		virtual bool operator==(const Input&) const = 0; // Declarar função fora da classe? Livro de C++ em um dos capítulos lá fala disso
		virtual std::size_t Hash() const = 0;
	protected:

	};
}

#endif // _INPUT_