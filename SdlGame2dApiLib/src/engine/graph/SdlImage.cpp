#include "engine/Engine.h"

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

void SdlImage::ChangeTexture(const std::string& filePath, const SDL_Color& transparencyColor)
{
	const SdlWindow* pScreen = dynamic_cast<const SdlWindow*>(&Engine::Screen());
	if (pScreen)
	{
		pTexture = pScreen->CreateTexture(filePath, transparencyColor);
		configuration.AutoConfigure(pTexture);
	}
}

void SdlImage::ChangeTexture(const std::string& filePath, const RenderingConfiguration& newConfiguration)
{
	ChangeTexture(filePath);
	configuration = newConfiguration;
}

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
		SDL_Rect clip = configuration.clip;
		SDL_Rect renderQuad = { configuration.position.x, configuration.position.y,
								configuration.dimension.w, configuration.dimension.h };

		SDL_Point center = configuration.rotation.center;
		SDL_RendererFlip flip = configuration.rotation.flip;

		SDL_RenderCopyEx(pWindow->pRenderer, &(*pTexture),  // TO_DO Melhorar o modo como Window->pRenderer é acessado
			&clip,
			&renderQuad,
			configuration.rotation.angle, &center, flip);
	}
}