#ifndef _SCREEN_
#define _SCREEN_

namespace graph
{
	class Screen // TODO Pensar se é melhor Image::Print(Screen) ou Screen::Print(Image)
	{
	public:
		Screen() {};
		virtual ~Screen() {};

		virtual void Clear() = 0;

	private:
		Screen(const Screen&);
		Screen& operator=(const Screen&);
	};
}

#endif // _SCREEN_