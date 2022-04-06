#ifndef _SDL_WINDOW_
#define _SDL_WINDOW_

#include <exception>
#include <memory>
#include <string>

#include <SDL.h>

#include "Screen.h"

namespace graph
{
	namespace sdl
	{
		class SdlWindow : public Screen
		{
		friend class Image; // TO_DO SdlImage tem acesso a pWindow mas só precisa do pRenderer. Como melhorar isto?

		public:
			explicit SdlWindow(int width, int height, std::string title = "", bool fullScreen = false);
			~SdlWindow();

			void Clear() override;
			void Update() override;

			std::shared_ptr<SDL_Texture> CreateTexture(std::string filePath);
			std::shared_ptr<SDL_Texture> CreateTexture(std::string filePath, const SDL_Color& transparencyColor);

		private:
			SDL_Window* pWindow;
			SDL_Renderer* pRenderer;
		};

		inline void DeleteTexture(SDL_Texture* texture)
		{
			if (texture != NULL)
			{
				SDL_DestroyTexture(texture);
				texture = NULL;
			}
		}

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
	}
}

#endif // _SDL_WINDOW_