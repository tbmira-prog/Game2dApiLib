#ifndef _INPUT_
#define _INPUT_

namespace input
{
	class Input
	{
	public:
		Input();
		virtual ~Input();

		virtual bool operator==(const Input&) const = 0;

	protected:

	};
}

#endif // _INPUT_