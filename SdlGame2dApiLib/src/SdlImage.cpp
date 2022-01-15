#include "SdlImage.h"
#include "Window.h"
using namespace graph::sdl;

SdlImage::SdlImage() : Image(), pTexture(), renderQuad(), center(), clip(), flipMode(), angle(0.0) {}

SdlImage::SdlImage(std::string file) : Image(), pTexture(), renderQuad(), center(), clip(), flipMode(), angle(0.0)
{
	Load(file);
}

SdlImage::~SdlImage()
{
	// TODO Free();
}

SdlImage::SdlImage(const SdlImage& otherImage) : Image(otherImage), pTexture(otherImage.pTexture),
												 renderQuad(otherImage.renderQuad), center(otherImage.center),
												 clip(otherImage.clip), flipMode(otherImage.flipMode), angle(otherImage.angle)
{}

SdlImage& SdlImage::operator=(const SdlImage& otherImage)
{
	pTexture = otherImage.pTexture;
	renderQuad = otherImage.renderQuad;
	center = otherImage.center;
	clip = otherImage.clip;
	flipMode = otherImage.flipMode;
	angle = otherImage.angle;

	return *this;
}

void SdlImage::Load(std::string filePath)
{
	Free();

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if (loadedSurface == NULL)
    {
		SDL_FreeSurface(loadedSurface);
		throw;
    }

    pTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface); // TODO o porra kkkkk como que vai fazer pra acessar esse renderer
    if (pTexture == NULL)
    {
		SDL_FreeSurface(loadedSurface);
        throw;
    }

	SDL_FreeSurface(loadedSurface);
}

void SdlImage::Print(Screen& screen) const
{
	Window* pWindow = dynamic_cast<Window*>(&screen);
	
	if (pWindow != nullptr)
		SDL_RenderCopyEx(pWindow->pRenderer, &(*pTexture), &clip, &renderQuad, angle, &center, flipMode);
}

void SdlImage::Free() // TODO Podem ter outras SdlImages usando o mesmo ponteiro. Usar shared_ptr. Tem que pesquisar sobre o deleter
{
	/*if (pTexture != NULL)
	{
		SDL_DestroyTexture(pTexture);
		*this = SdlImage();
	}*/
}