#ifndef _SDL_IMAGE_
#define _SDL_IMAGE_

#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Image.h"

namespace graph
{
	namespace sdl
	{
		class SdlImage : public Image
		{
		public:
			SdlImage();
			SdlImage(std::string file);

			SdlImage(const SdlImage&);
			SdlImage& operator=(const SdlImage&);

			~SdlImage();

			void Load(std::string filePath);
			void Print(Screen& screen) const;

			void Free();

		private:
			std::shared_ptr<SDL_Texture> pTexture;
			
			// TODO Setters e Getters, public, organizar em struct???
		public:
			SDL_Point center;
			SDL_Rect renderQuad, clip;
			SDL_RendererFlip flipMode;
			double angle;
		};
	}
}

#endif // _SDL_IMAGE_