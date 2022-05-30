#ifdef __linux__ 
//linux code goes here // UNDONE Biblioteca para esconder terminal no linux
#elif _WIN32
#include <windows.h>
#else
// ... // UNDONE Biblioteca para esconder terminal em outras plataformas
#endif

#include <cstdlib>
#include <iostream>

#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SdlWindow.h"
#include "SdlWindowException.h"
using namespace engine::graph::sdl;

void HideConsole()
{
#ifdef __linux__ 
	// Linux code goes here // UNDONE Esconder terminal no linux
#elif _WIN32
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#else
	// UNDONE Esconder terminal em outras plataformas
#endif
}

SdlWindow::SdlWindow(int width, int height, std::string title, bool fullScreen) : Screen(), pWindow(nullptr), pRenderer(nullptr)
{
	try
	{
		HideConsole();

		if (SDL_Init(SDL_INIT_VIDEO) < 0) // TO_DO Será possível iniciar o SDL com Audio em AudioPlayer? Ou dever ser feito tudo nesta classe?
			throw  FailedToInitializateSDL();

		// TODO Configurar título da tela e outras opções (flags)
		pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | (SDL_WINDOW_FULLSCREEN_DESKTOP && fullScreen));
		if (pWindow == NULL)
			throw FailedToCreateWindow();

		pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == NULL)
			throw FailedToCreateRenderer();

		if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
			throw FailedToInitiateSDLImage();

		if (TTF_Init() == -1)
			throw FailedToInitiateSdlTtf();
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what();
		std::abort();
	}
}

SdlWindow::~SdlWindow()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	pRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

void SdlWindow::Clear()
{
	SDL_RenderClear(pRenderer);
}

void SdlWindow::Update()
{
	SDL_RenderPresent(pRenderer);
}

std::shared_ptr<SDL_Texture> SdlWindow::CreateTexture(std::string filePath) const
{
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if (loadedSurface == NULL)
		throw FailedToCreateTexture();

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	
	if (newTexture)
	{
		std::shared_ptr<SDL_Texture> pTexture(newTexture, DeleteTexture);
		return pTexture;
	}
	else
		throw FailedToCreateTexture();
}

std::shared_ptr<SDL_Texture> SdlWindow::CreateTexture(std::string filePath, const SDL_Color& transparencyColor) const // UNDONE Código duplicado
{
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if (loadedSurface == NULL)
		throw FailedToCreateTexture();

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, transparencyColor.r, transparencyColor.g, transparencyColor.b));

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	if (newTexture)
	{
		std::shared_ptr<SDL_Texture> pTexture(newTexture, DeleteTexture);
		return pTexture;
	}
	else
		throw FailedToCreateTexture();
}

size_t SdlWindow::Width() const
{
	int w = 0, h = 0;
	SDL_GetWindowSize(pWindow, &w, &h);
	return w;
}

size_t SdlWindow::Height() const
{
	int w = 0, h = 0;
	SDL_GetWindowSize(pWindow, &w, &h);
	return h;
}

//void DeleteTexture(SDL_Texture* texture)
//{
//	if (texture != NULL)
//	{
//		SDL_DestroyTexture(texture);
//		texture = NULL;
//	}
//}