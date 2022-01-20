#ifndef _SCREEN_
#define _SCREEN_

namespace graph
{
	class Screen // TO_DO Pensar se é melhor Image::Print(Screen) ou Screen::Print(Image)
	{
	public:
		Screen() {};
		virtual ~Screen() {};

		virtual void Clear() = 0;
		virtual void Update() = 0;

	private:
		Screen(const Screen&) = delete;
		Screen& operator=(const Screen&) = delete;
	};
}

#endif // _SCREEN_