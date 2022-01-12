#ifndef _SDL_IMAGE_
#define _SDL_IMAGE_

#include <SDL.h>

#include "Image.h"

namespace graph
{
	namespace sdl
	{
		class SdlImage : public Image
		{
		public:
			SdlImage();
			//SdlImage(...);

			~SdlImage();

			//void Load();
			void Print(Screen& screen) const;

		private:
			SDL_Texture* pTexture;
			size_t width, height;
		};
	}
}

#endif // _SDL_IMAGE_