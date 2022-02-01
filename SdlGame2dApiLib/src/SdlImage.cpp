#include "SdlImage.h"
#include "SdlWindow.h"
using namespace graph::sdl;

Image::Image() : graph::Image(), pTexture(), configuration() {}

Image::Image(SDL_Texture* pNewTexture) : graph::Image(), pTexture(pNewTexture, DeleteTexture), configuration(pNewTexture) {}

Image::Image(std::shared_ptr<SDL_Texture> pNewTexture) : graph::Image(), pTexture(pNewTexture), configuration(&(*pNewTexture))
{
	if (auto pDel = std::get_deleter<void(*)(SDL_Texture*)>(pTexture))
		if (*pDel != DeleteTexture)
			pTexture.reset(pNewTexture.get(), DeleteTexture); // UNDONE Código duplicado
}

Image::Image(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration) : graph::Image(),
																						 pTexture(pNewTexture, DeleteTexture),
																						 configuration(newConfiguration)
{}

Image::Image(std::shared_ptr<SDL_Texture> pNewTexture, const RenderingConfiguration& newConfiguration) : graph::Image(),
																										 pTexture(pNewTexture),
																										 configuration(newConfiguration)
{
	if (auto pDel = std::get_deleter<void(*)(SDL_Texture*)>(pTexture))
		if (*pDel != DeleteTexture)
			pTexture.reset(pNewTexture.get(), DeleteTexture); // UNDONE Código duplicado
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

void Image::ChangeTexture(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration)
{
	pTexture.reset(pNewTexture, DeleteTexture);
	if (!pTexture)
		throw InvalidTexture();

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