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

SdlText::SdlText(TTF_Font* pFont, const std::string& text) : pFont(pFont, DeleteFont), text(text), textColor({ 0xFF, 0xFF, 0xFF })
{
	SetText(text);
}

SdlText::SdlText(std::shared_ptr<TTF_Font> pNewFont, const std::string& text) : pFont(pNewFont), text(text), textColor({ 0xFF, 0xFF, 0xFF })
{
	if (auto pDel = std::get_deleter<void(*)(TTF_Font*)>(pFont))
		if (*pDel != DeleteFont)
			pFont.reset(pNewFont.get(), DeleteFont);

	SetText(text);
}

SdlText::SdlText(const std::string& fontFilePath, int fontSize, const SDL_Color& textColor, const std::string& text) : pFont(), text(text), textColor(textColor)
{
	ChangeFont(fontFilePath, fontSize);
	SetText(text);
}

SdlText::~SdlText()
{}

void SdlText::SetText(const std::string& newText)
{
	this->text = newText;

	if (text == "")
		return;

    SDL_Surface* pTextSurface = TTF_RenderText_Solid(pFont.get(), text.c_str(), textColor);
    if (pTextSurface == NULL)
        throw FailToCreateSurface();

	ChangeTexture(pTextSurface);

    SDL_FreeSurface(pTextSurface);
}

std::string SdlText::Text() const
{
	return text;
}

void SdlText::ChangeFont(TTF_Font* pNewFont)
{
	if(pNewFont)
		pFont.reset(pNewFont, DeleteFont);
	//else // TODO Avisar programador de erro na Font
	//	...
}

void SdlText::ChangeFont(const std::shared_ptr<TTF_Font>& pNewFont)
{
	pFont.reset(pNewFont.get(), DeleteFont);
}

void SdlText::ChangeFont(const std::string& fontFilePath, int fontSize)
{
	TTF_Font* pNewFont = TTF_OpenFont(fontFilePath.c_str(), fontSize);
	if (!pNewFont)
		throw FailToSetFont();

	pFont.reset(pNewFont, DeleteFont);
}

//void SdlText::ChangeFontSize(const int newSize) // TODO Fazer função para trocar tamanho da fonte
//{
//	
//}

void SdlText::ChangeFontColor(const SDL_Color& newColor)
{
	textColor = newColor;
}

int SdlText::GetFontSize() const
{
	return TTF_FontHeight(pFont.get());
}

SDL_Color SdlText::GetFontCollor() const
{
	return textColor;
}

//bool SdlText::CheckFontDeleter(std::shared_ptr<TTF_Font> pNewFont)
//{
//	if (auto pDel = std::get_deleter<void(*)(TTF_Font*)>(pFont))
//		return (*pDel != DeleteFont) ? false : true;	
//}