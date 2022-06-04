#ifndef _SDL_IMAGE_
#define _SDL_IMAGE_

#include <exception>
#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>

#include "engine/graph/Image.h"
#include "RenderingConfiguration.h"

namespace engine
{
	namespace graph // TO_DO Implementar swap para as classes que precisarem
	{
		namespace sdl
		{
			class SdlImage : public Image
			{
			public:
				SdlImage();
				SdlImage(const std::string& filePath, const SDL_Color& transparencyColor = SDL_Color{ 200, 200, 200, 0 });
				explicit SdlImage(SDL_Texture* pNewTexture);
				explicit SdlImage(std::shared_ptr<SDL_Texture> pNewTexture);

				explicit SdlImage(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration);
				explicit SdlImage(std::shared_ptr<SDL_Texture> pNewTexture, const RenderingConfiguration& newConfiguration);

				SdlImage(const SdlImage&);
				SdlImage& operator=(const SdlImage&);

				~SdlImage();

				// TO_DO Melhorar interface das funções de carregar imagens
				void ChangeTexture(const std::string& filePath, const SDL_Color& transparencyColor = SDL_Color{200, 200, 200, 0});
				void ChangeTexture(const std::string& filePath, const RenderingConfiguration& newConfiguration);
				void ChangeTexture(SDL_Surface* pSurface);
				void ChangeTexture(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration); // UNDONE Precisa desta função ou basta usar os construtores?

				void Print(Screen& screen) const override;

				RenderingConfiguration configuration; // HACK Referências diferentes com RC diferentes compartilhando a mesma texture
			private:
				std::shared_ptr<SDL_Texture> pTexture;
			};

			struct InvalidTexture : public std::exception
			{
				const char* what() const override { return "Invalid texture was passed to sdl::Image!\n"; }
			};
		}
	}
}

#endif // _SDL_IMAGE_