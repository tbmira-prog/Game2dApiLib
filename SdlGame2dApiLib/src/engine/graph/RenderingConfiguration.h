#ifndef _RENDERING_CONFIGURATION_
#define _RENDERING_CONFIGURATION_

#include <stdexcept>

#include <SDL.h>

namespace engine
{
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

			class RenderingConfiguration // TODO Melhorar acesso a essas classes, é fácil de confundir a ordem dos x, y, w, h, etc;
			{
			public:
				RenderingConfiguration() {}

				RenderingConfiguration(SDL_Texture* pTexture) : renderQuad(), clip(), rotation() {
					int w = 0, h = 0;
					SDL_QueryTexture(pTexture, NULL, NULL, &w, &h);
					renderQuad = { 0, 0, w, h };
				}

				//RenderingConfiguration(const RenderQuad& rQ, const Clip& c, const Rotation& rt) : renderQuad(rQ), clip(c), rotation(rt) {};

				/*void SetRenderQuad(const RenderQuad& r)
				{
					if (r.renderQuad.x < 0 || r.renderQuad.y < 0 || r.renderQuad.w < 0 || r.renderQuad.h < 0)
						throw std::logic_error("Negatives values in renderQuad!");

					renderQuad = r;
				}
				RenderQuad GetRenderQuad() const { return renderQuad; }

				void SetClip(const Clip& c)
				{
					if (c.clip.x < 0 || c.clip.y < 0 || c.clip.w < 0 || c.clip.h < 0)
						throw std::logic_error("Negatives values in Clip!");

					clip = c;
				}
				Clip GetClip() const { return clip; }

				void Rotate(const Rotation& r)
				{
					if (0)  // TO_DO Checagens em Set
						throw std::logic_error("Negatives values in Clip!");

					rotation = r;
				}
				Rotation GetRotation() const { return rotation; }

//			private:*/
				SDL_Rect renderQuad;
				SDL_Rect clip;
				Rotation rotation;
			};
		}
	}
}

#endif // _RENDERING_CONFIGURATION_