#ifndef _SDL_TEXT_
#define _SDL_TEXT_

#include <memory>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SdlImage.h"

namespace engine
{
	namespace graph
	{
		namespace sdl
		{
			class SdlText : public SdlImage
			{
			public:
				SdlText(TTF_Font* pFont, const std::string& text = "");
				SdlText(std::shared_ptr<TTF_Font> pFont, const std::string& text = "");
				SdlText(const std::string& fontFilePath, int fontSize, const SDL_Color& textColor, const std::string& text = "");
				~SdlText();
				
				void SetText(const std::string& text);
				std::string Text() const;

				void ChangeFont(TTF_Font* pFont);
				void ChangeFont(const std::shared_ptr<TTF_Font>& pFont);
				void ChangeFont(const std::string& fontFilePath, int fontSize);

				void ChangeFontSize(const int newSize);
				void ChangeFontColor(const SDL_Color& newColor);
				
				int GetFontSize() const;
				SDL_Color GetFontCollor() const;

			private:
				std::shared_ptr<TTF_Font> pFont;
				std::string text;
				SDL_Color textColor;
			};

			void DeleteFont(TTF_Font* pFont);

			struct FailToSetFont : public std::exception
			{
				const char* what() const override { return "Fail to set the Font to the Text!\n"; }
			};

			struct FailToCreateSurface : public std::exception
			{
				const char* what() const override { return "Fail to create Surface in Texture changing!\n"; }
			};
		}
	}
}

#endif // _SDL_TEXT_
