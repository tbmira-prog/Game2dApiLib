#ifndef _WINDOW_
#define _WINDOW_

#include <SDL.h>

#include "Screen.h"

namespace graph
{
	namespace sdl
	{
		class Window : public Screen
		{
		friend class SdlImage; // TODO SdlImage tem acesso a pWindow mas só precisa do pRenderer. Como melhorar isto?

		public:
			Window(int width, int height);
			~Window();

			void Clear();

		private:
			SDL_Window* pWindow;
			SDL_Renderer* pRenderer;
		};
	}
}

#endif // _WINDOW_