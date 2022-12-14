#ifndef _SDL_WINDOW_
#define _SDL_WINDOW_

#include <exception>
#include <memory>
#include <string>

#include <SDL.h>

#include <engine/graph/Screen.h>

namespace engine
{
	namespace graph
	{
		namespace sdl
		{
			class SdlWindow : public Screen
			{
				friend class SdlImage; // TO_DO SdlImage tem acesso a pWindow mas s? precisa do pRenderer. Como melhorar isto?

			public:
				explicit SdlWindow(int width, int height, std::string title = "", bool fullScreen = false);
				~SdlWindow();

				void Clear() override;
				void Update() override;

				std::shared_ptr<SDL_Texture> CreateTexture(std::string filePath) const;
				std::shared_ptr<SDL_Texture> CreateTexture(std::string filePath, const SDL_Color& transparencyColor) const;
				std::shared_ptr<SDL_Texture> CreateTexture(SDL_Surface* pSurface) const;

				size_t Width() const override;
				size_t Height() const override;

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

		}
	}
}

#endif // _SDL_WINDOW_