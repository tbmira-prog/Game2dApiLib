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
	// TODO Gerenciamento de memória para SdlImagens no destrutor
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

    pTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface); // HACK Como que vai fazer pra acessar Window::pRenderer sem que os clientes precisem passar o renderer como argumento para esta função ou para o construtor?
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

void SdlImage::Free() // HACK Podem ter outras SdlImages usando o mesmo ponteiro. Usar shared_ptr. Tem que pesquisar sobre o deleter
{
	/*if (pTexture != NULL)
	{
		SDL_DestroyTexture(pTexture);
		*this = SdlImage();
	}*/
}