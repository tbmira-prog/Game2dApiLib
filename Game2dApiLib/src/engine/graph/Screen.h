#ifndef _SCREEN_
#define _SCREEN_

namespace engine
{
	namespace graph
	{
		class Screen
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
}

#endif // _SCREEN_