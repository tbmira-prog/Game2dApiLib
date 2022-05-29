#ifndef _SDL_TEXT_
#define _SDL_TEXT_

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <engine/graph/Image.h>

namespace engine
{
	namespace graph
	{
		namespace sdl
		{
			class SdlText : public engine::graph::Image
			{
			public:
				SdlText();
				~SdlText();

				void Print(engine::graph::Screen&) const override;
			};

		}
	}
}

#endif // _SDL_TEXT_
