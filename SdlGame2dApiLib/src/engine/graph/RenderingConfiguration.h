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
				Dimension2D() : w(0), h(0) {}
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

			class RenderingConfiguration
			{
			public:
				RenderingConfiguration();

				RenderingConfiguration( const SDL_Point& position = { 0, 0 },
										int width = 0, int height = 0,
										const SDL_Rect& clip = {0, 0, 0, 0}, 
										const Rotation& rotation = Rotation(0.0),
										const SDL_Color& transparencyColor = { 0, 0xFF, 0xFF });
				
				RenderingConfiguration(SDL_Texture* pTexture, const SDL_Color& transparencyColor = { 0, 0xFF, 0xFF });
				RenderingConfiguration(std::shared_ptr<SDL_Texture> pTexture, const SDL_Color& transparencyColor = { 0, 0xFF, 0xFF });
				
				RenderingConfiguration(const RenderingConfiguration&);
				RenderingConfiguration& operator=(const RenderingConfiguration&);

				void AutoConfigure(SDL_Texture* pTexture);
				void AutoConfigure(std::shared_ptr<SDL_Texture> pTexture);

				void SetPosition(int x, int y);
				void SetPosition(const SDL_Point& point);
				SDL_Point Position() const;

				void SetDimensions(int w, int h);
				SDL_Rect RenderQuad() const;

				void SetClip(int x, int y, int w, int h);
				void SetClip(const SDL_Rect& c);
				SDL_Rect GetClip() const;

				void Rotate(const Rotation& r);
				Rotation GetRotation() const { return rotation; }

				void ChangeTransparencyCollor(const SDL_Color&);

				SDL_Point position;
				Dimension2D dimension;
				SDL_Rect clip;
				Rotation rotation;
			private:
				SDL_Color transparencyColor;
			};
		}
	}
}

#endif // _RENDERING_CONFIGURATION_