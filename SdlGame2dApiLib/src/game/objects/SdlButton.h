#ifndef _SDL_BUTTON_
#define _SDL_BUTTON_

//#include <string>

#include <game/GameObject.h>

#include <engine/graph/SdlImage.h>
#include <engine/input/SdlInput.h>

namespace game
{
	namespace sdl
	{
		enum class ButtonState {CLICKED, HOLD, MOUSE_OVER, MOUSE_OUT};

		class SdlButton : public GameObject
		{
		public:
			SdlButton();
			SdlButton(	const engine::graph::sdl::SdlImage& buttonImage, const SDL_Rect& clipOut,
						const SDL_Rect& clipOver, const SDL_Rect& clipClicked);
			virtual ~SdlButton();

			virtual void LoadMedia() override;
			virtual void HandleInput(const engine::input::Input&) override;
			
			virtual ButtonState State() const { return state; }
			virtual bool Clicked() const { return state == ButtonState::CLICKED; }

			engine::graph::sdl::SdlImage& Image() { return buttonImage; } // TODO Melhorar isso, retornando referência para internos

			void SetImage(const engine::graph::sdl::SdlImage& buttonImage, const SDL_Rect& clipOut,
					      const SDL_Rect& clipOver, const SDL_Rect& clipClicked);

		private:
			engine::graph::sdl::SdlImage buttonImage;
			SDL_Rect clipOut, clipOver, clipClicked;

			ButtonState state;

			virtual bool MouseOver(const SDL_Point& mousePosition) const;

			void ClickedHandle(const engine::input::sdl::SdlInput& i);
			void HoldHandle(const engine::input::sdl::SdlInput& i);
			void MouseOverHandle(const engine::input::sdl::SdlInput& i);
			void MouseOutHandle(const engine::input::sdl::SdlInput& i);
		};
	}
}

#endif // _SDL_BUTTON_
