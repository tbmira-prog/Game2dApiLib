#include "SdlImage.h"
#include "SdlWindow.h"
using namespace graph::sdl;

Image::Image() : graph::Image(), pTexture(), configuration() {}

Image::Image(SDL_Texture* pNewTexture) : graph::Image(), pTexture(pNewTexture, TextureDeleter()), configuration()
{}

Image::Image(std::shared_ptr<SDL_Texture> pNewTexture) : graph::Image(), pTexture(pNewTexture), configuration()
{
	// UNDONE Checar deleter
}

Image::Image(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration) : graph::Image(),
																						 pTexture(pNewTexture, TextureDeleter()),
																						 configuration()
{}

Image::Image(std::shared_ptr<SDL_Texture> pNewTexture, const RenderingConfiguration& newConfiguration) : graph::Image(),
																										 pTexture(pNewTexture),
																										 configuration()
{
	// UNDONE Checar deleter
}

Image::Image(const Image& otherImage) : graph::Image(otherImage), pTexture(otherImage.pTexture), configuration(otherImage.configuration)
{}

Image& Image::operator=(const Image& otherImage)
{
	pTexture = otherImage.pTexture;
	configuration = otherImage.configuration;

	return *this;
}

Image::~Image() {}

void Image::Load(SDL_Texture* pNewTexture)
{
	pTexture.reset(pNewTexture, TextureDeleter());
    if (!pTexture)
        throw; // TO_DO throw quando textura não for carregada ou não?
}

void Image::Load(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration)
{
	Load(pNewTexture);
	configuration = newConfiguration;
}

void Image::Print(Screen& screen) const
{
	Window* pWindow = dynamic_cast<Window*>(&screen);
	
	if (pWindow != nullptr)
	{
		SDL_Rect clip = configuration.GetClip().clip;
		SDL_Rect renderQuad = configuration.GetRenderQuad().renderQuad;
		SDL_Point center = configuration.GetRotation().center;
		SDL_RendererFlip flip = configuration.GetRotation().flip;

		SDL_RenderCopyEx(pWindow->pRenderer, &(*pTexture),  // TO_DO Melhorar o modo como Window->pRenderer é acessado
			&clip,
			&renderQuad,
			configuration.GetRotation().angle, &center, flip);
	}
}