#include "SdlImage.h"
#include "SdlWindow.h"
using namespace engine::graph::sdl;

SdlImage::SdlImage() : Image(), pTexture(), configuration() {}

SdlImage::SdlImage(SDL_Texture* pNewTexture) : Image(), pTexture(pNewTexture, DeleteTexture), configuration(pNewTexture) {}

SdlImage::SdlImage(std::shared_ptr<SDL_Texture> pNewTexture) : Image(), pTexture(pNewTexture), configuration(&(*pNewTexture))
{
	if (auto pDel = std::get_deleter<void(*)(SDL_Texture*)>(pTexture))
		if (*pDel != DeleteTexture)
			pTexture.reset(pNewTexture.get(), DeleteTexture); // UNDONE Código duplicado
}

SdlImage::SdlImage(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration) : Image(),
																								pTexture(pNewTexture, DeleteTexture),
																								configuration(newConfiguration)
{}

SdlImage::SdlImage(std::shared_ptr<SDL_Texture> pNewTexture, const RenderingConfiguration& newConfiguration) : graph::Image(),
																												 pTexture(pNewTexture),
																												 configuration(newConfiguration)
{
	if (auto pDel = std::get_deleter<void(*)(SDL_Texture*)>(pTexture))
		if (*pDel != DeleteTexture)
			pTexture.reset(pNewTexture.get(), DeleteTexture); // UNDONE Código duplicado
}

SdlImage::SdlImage(const SdlImage& otherImage) : Image(otherImage), pTexture(otherImage.pTexture), configuration(otherImage.configuration)
{}

SdlImage& SdlImage::operator=(const SdlImage& otherImage)
{
	pTexture = otherImage.pTexture;
	configuration = otherImage.configuration;

	return *this;
}

SdlImage::~SdlImage() {}

void SdlImage::ChangeTexture(SDL_Texture* pNewTexture, const RenderingConfiguration& newConfiguration)
{
	pTexture.reset(pNewTexture, DeleteTexture);
	if (!pTexture)
		throw InvalidTexture();

	configuration = newConfiguration;
}

void SdlImage::Print(Screen& screen) const
{
	SdlWindow* pWindow = dynamic_cast<SdlWindow*>(&screen);
	
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