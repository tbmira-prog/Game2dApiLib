#ifdef __linux__ 
//linux code goes here // UNDONE Biblioteca para esconder terminal no linux
#elif _WIN32
#include <windows.h>
#else
// ... // UNDONE Biblioteca para esconder terminal em outras plataformas
#endif

#include <SDL_image.h>

#include "SdlWindow.h"
using namespace graph::sdl;

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

Window::Window(int width, int height, std::string title, bool fullScreen) : Screen(), pWindow(nullptr), pRenderer(nullptr)
{ // HACK Configurar título da tela e outras opções (flags)
	try
	{
		HideConsole();

		if (SDL_Init(SDL_INIT_VIDEO) < 0) // TO_DO Será possível iniciar o SDL com Audio em AudioPlayer? Ou dever ser feito tudo nesta classe?
			throw;

		pWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (pWindow == NULL)
			throw;

		pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (pRenderer == NULL)
			throw;

		if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
			throw;
	}
	catch (...)
	{
		// TO_DO Abort caso falhe em criar janela
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	pRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

void Window::Clear()
{
	SDL_RenderClear(pRenderer);
}

void Window::Update()
{
	SDL_RenderPresent(pRenderer);
}

std::shared_ptr<SDL_Texture> Window::CreateTexture(std::string filePath)
{
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if (loadedSurface == NULL)
		throw; // TO_DO Lançar excessão caso falhe em criar textura

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	
	if (newTexture)
	{
		std::shared_ptr<SDL_Texture> pTexture(newTexture, TextureDeleter());
		return pTexture;
	}
	else
		throw; // TO_DO Lançar excessão caso falhe em criar textura
}

std::shared_ptr<SDL_Texture> Window::CreateTexture(std::string filePath, const SDL_Color& transparencyColor) // UNDONE Código duplicado
{
	SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
	if (loadedSurface == NULL)
		throw; // TO_DO Lançar excessão caso falhe em criar textura

	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, transparencyColor.r, transparencyColor.g, transparencyColor.b));

	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);

	if (newTexture)
	{
		std::shared_ptr<SDL_Texture> pTexture(newTexture, TextureDeleter());
		return pTexture;
	}
	else
		throw; // TO_DO Lançar excessão caso falhe em criar textura
}

void TextureDeleter::operator()(SDL_Texture* texture)
{
	if (texture != NULL)
		SDL_DestroyTexture(texture);
}