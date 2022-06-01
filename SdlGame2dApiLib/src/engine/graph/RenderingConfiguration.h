#ifndef _RENDERING_CONFIGURATION_
#define _RENDERING_CONFIGURATION_

#include <memory>
#include <stdexcept>

#include <SDL.h>

namespace engine
{
	namespace graph
	{
		namespace sdl
		{
			struct Dimension2D
			{
				Dimension2D(int w = 0, int h = 0) : w(w), h(h) {}
				int w, h;
			};

			struct Rotation
			{
				Rotation();
				Rotation(double newAngle, SDL_Point newCenter = { 0, 0 }, SDL_RendererFlip newFlip = SDL_RendererFlip::SDL_FLIP_NONE);

				SDL_Point center;
				SDL_RendererFlip flip;
				double angle;
			};

			struct RenderingConfiguration
			{
				RenderingConfiguration();

				RenderingConfiguration( const SDL_Point& position,
										const Dimension2D& dimension,
										const SDL_Rect& clip, 
										const Rotation& rotation = Rotation(0.0) );
				
				RenderingConfiguration(SDL_Texture* pTexture);
				RenderingConfiguration(const std::shared_ptr<SDL_Texture>& pTexture);
				
				RenderingConfiguration(const RenderingConfiguration&) = default;
				RenderingConfiguration& operator=(const RenderingConfiguration&) = default;

				void AutoConfigure(SDL_Texture* pTexture);
				void AutoConfigure(const std::shared_ptr<SDL_Texture>& pTexture);

				void SetPosition(int x, int y);
				void SetPosition(const SDL_Point& point);
				SDL_Point Position() const;

				void SetDimensions(int w, int h);
				Dimension2D Dimension() const;

				void SetClip(int x, int y, int w, int h);
				void SetClip(const SDL_Rect& c);
				SDL_Rect GetClip() const;

				void Rotate(const Rotation& r);
				Rotation GetRotation() const;

				SDL_Point position;
				Dimension2D dimension;
				SDL_Rect clip;
				Rotation rotation;
			};
		}
	}
}

#endif // _RENDERING_CONFIGURATION_