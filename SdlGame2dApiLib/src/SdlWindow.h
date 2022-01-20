#ifndef _SDL_WINDOW_
#define _SDL_WINDOW_

#include <memory>
#include <string>

#include <SDL.h>

#include "Screen.h"

namespace graph
{
	namespace sdl
	{
		class Window : public Screen
		{
		friend class Image; // TO_DO SdlImage tem acesso a pWindow mas só precisa do pRenderer. Como melhorar isto?

		public:
			explicit Window(int width, int height, std::string title = "", bool fullScreen = false);
			~Window();

			void Clear() override;
			void Update() override;

			std::shared_ptr<SDL_Texture> CreateTexture(std::string filePath);
			std::shared_ptr<SDL_Texture> CreateTexture(std::string filePath, const SDL_Color& transparencyColor);

		private:
			SDL_Window* pWindow;
			SDL_Renderer* pRenderer;
		};

		struct TextureDeleter // UNDONE SdlImage::operator delete();
		{
			void operator()(SDL_Texture* texture);
		};
	}
}

#endif // _SDL_WINDOW_