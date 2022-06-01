#ifndef _SDL_WINDOW_EXCEPTION_
#define _SDL_WINDOW_EXCEPTION_

#include <exception>

namespace engine
{
	namespace graph
	{
		namespace sdl
		{
			// TODO Melhorar mensagens de erro
			struct FailedToCreateWindow : public std::exception
			{
				const char* what() const override { return "Failed to create window!\n"; }
			};

			struct FailedToCreateRenderer : public std::exception
			{
				const char* what() const override { return "Failed to create window!\n"; }
			};

			struct FailedToCreateTexture : public std::exception
			{
				const char* what() const override { return "Failed to create texture!\n"; }
			};

			struct FailedToInitializateSDL : public std::exception
			{
				const char* what() const override { return "Failed to create window!\n"; }
			};

			struct FailedToInitiateSDLImage : public std::exception
			{
				const char* what() const override { return "Failed to create window!\n"; }
			};

			struct FailedToInitiateSdlTtf : public std::exception
			{
				const char* what() const override { return "Failed to create window!\n"; }
			};

		}
	}
}

#endif // _SDL_WINDOW_EXCEPTION_