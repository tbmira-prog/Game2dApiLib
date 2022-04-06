#ifndef _SDL_IMAGE_
#define _SDL_IMAGE_

#include <exception>
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
		class SdlImage : public Image
		{
		public:
			SdlImage();
			explicit SdlImage(SDL_Texture* pNewTexture);
			explicit SdlImage(std::shared_ptr<SDL_Texture> pNewTexture);

			explicit SdlImage(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration );
			explicit SdlImage(std::shared_ptr<SDL_Texture> pNewTexture, const RenderingConfiguration& newConfiguration);

			SdlImage(const SdlImage&);
			SdlImage& operator=(const SdlImage&);

			~SdlImage();

			void ChangeTexture(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration); // UNDONE Precisa desta função ou basta usar os construtores?
			
			void Print(Screen& screen) const;

			RenderingConfiguration configuration;
		private:
			std::shared_ptr<SDL_Texture> pTexture;
		};

		struct InvalidTexture : public std::exception
		{
			const char* what() const override { return "Invalid texture was passed to sdl::Image!\n"; }
		};
	}
}

#endif // _SDL_IMAGE_