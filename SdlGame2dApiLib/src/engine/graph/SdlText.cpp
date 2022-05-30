#include "SdlText.h"
#include "SdlWindow.h"
using namespace engine::graph::sdl;

#include <engine/Engine.h>

void engine::graph::sdl::DeleteFont(TTF_Font* pFont)
{
	if (pFont != NULL)
	{
		TTF_CloseFont(pFont);
		pFont = NULL;
	}
}

SdlText::SdlText(TTF_Font* pFont, const std::string& text = "") : pFont(pFont, DeleteFont), text(text)
{}

SdlText::SdlText(std::shared_ptr<TTF_Font> pNewFont, const std::string& text = "") : pFont(pNewFont), text(text)
{
	if (auto pDel = std::get_deleter<void(*)(TTF_Font*)>(pFont))
		if (*pDel != DeleteFont)
			pFont.reset(pNewFont.get(), DeleteFont);
}

SdlText::SdlText(const std::string& fontFilePath, int fontSize, const std::string& text = "") : pFont(), text(text)
{

}

SdlText::~SdlText()
{}

void SdlText::SetText(const std::string& newText)
{
	this->text = newText;

    SDL_Surface* textSurface = TTF_RenderText_Solid(pFont.get(), text.c_str(), textColor);
    if (textSurface == NULL)
        throw;

    //Create texture from surface pixels
	ChangeTexture(textSurface);

    SDL_FreeSurface(textSurface);
}

std::string SdlText::Text() const
{
	return text;
}

void SdlText::ChangeFont(TTF_Font* pNewFont)
{
	pFont.reset(pNewFont, DeleteFont);
}

void SdlText::ChangeFont(std::shared_ptr<TTF_Font> pNewFont)
{
	pFont = pNewFont;

	if (auto pDel = std::get_deleter<void(*)(TTF_Font*)>(pFont))
		if (*pDel != DeleteFont)
			pFont.reset(pNewFont.get(), DeleteFont);
}

void SdlText::ChangeFont(const std::string& fontFilePath, int fontSize)
{
	TTF_Font* pNewFont = TTF_OpenFont(fontFilePath.c_str(), fontSize);
	if (!pNewFont)
		throw;

	pFont.reset(pNewFont, DeleteFont);
}

//bool SdlText::CheckFontDeleter(std::shared_ptr<TTF_Font> pNewFont)
//{
//	if (auto pDel = std::get_deleter<void(*)(TTF_Font*)>(pFont))
//		return (*pDel != DeleteFont) ? false : true;	
//}