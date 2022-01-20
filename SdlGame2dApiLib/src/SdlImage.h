#ifndef _SDL_IMAGE_
#define _SDL_IMAGE_

#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>

#include "Image.h"
#include "RenderingConfiguration.h"

namespace graph // TO_DO Implementar swap para as classes que precisarem
{
	namespace sdl
	{
		class Image : public graph::Image
		{
		public:
			Image();
			explicit Image(SDL_Texture* pNewTexture);
			explicit Image(std::shared_ptr<SDL_Texture> pNewTexture);

			explicit Image(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration );
			explicit Image(std::shared_ptr<SDL_Texture> pNewTexture, const RenderingConfiguration& newConfiguration);

			Image(const Image&);
			Image& operator=(const Image&);

			~Image();

			void Load(SDL_Texture* pNewTexture); // UNDONE Precisa desta função ou basta usar os construtores?
			void Load(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration);
			
			void Print(Screen& screen) const;

			RenderingConfiguration configuration; // HACK Construtuores e funções Load devem setar renderQuad.w e renderQuad.h
		private:
			std::shared_ptr<SDL_Texture> pTexture;
		};

	}
}

#endif // _SDL_IMAGE_