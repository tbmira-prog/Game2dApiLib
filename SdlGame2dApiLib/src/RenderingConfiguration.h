#ifndef _RENDERING_CONFIGURATION_
#define _RENDERING_CONFIGURATION_

#include <SDL.h>

namespace graph
{
	namespace sdl
	{
		struct RenderQuad
		{
			RenderQuad() : renderQuad({ 0, 0,0,0 }) {}
			RenderQuad(int x, int y, int w, int h) : renderQuad({ x, y, w, h }) {}

			SDL_Rect renderQuad;
		};

		struct Clip
		{
			Clip() : clip({ 0, 0 }) {}
			Clip(int x, int y, int w, int h) : clip({ x, y, w, h }) {};

			SDL_Rect clip;
		};

		struct Rotation
		{
			Rotation() : center({ 0, 0 }), flip(SDL_FLIP_NONE), angle(0.0) {}

			Rotation(SDL_Point newCenter, SDL_RendererFlip newFlip, double newAngle) : center({ newCenter.x, newCenter.y }),
				flip(newFlip),
				angle(newAngle)
			{}

			SDL_Point center;
			SDL_RendererFlip flip;
			double angle;
		};

		class RenderingConfiguration
		{
		public:
			RenderingConfiguration() {}
			RenderingConfiguration(const RenderQuad& rQ, const Clip& c, const Rotation& rt) : renderQuad(rQ), clip(c), rotation(rt) {};

			void SetRenderQuad(const RenderQuad& r)
			{
				renderQuad = r; // TO_DO Checagens em Set
			}
			RenderQuad GetRenderQuad() const { return renderQuad; }

			void SetClip(const Clip& c) // TO_DO Checagens em Set
			{
				clip = c;
			}
			Clip GetClip() const { return clip; }

			void Rotate(const Rotation& r) // TO_DO Checagens em Set
			{
				rotation = r;
			}
			Rotation GetRotation() const { return rotation; }

		private:
			RenderQuad renderQuad;
			Clip clip;
			Rotation rotation;
		};
	}
}

#endif // _RENDERING_CONFIGURATION_