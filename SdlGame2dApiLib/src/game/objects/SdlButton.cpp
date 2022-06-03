#include "SdlButton.h"
using namespace game::sdl;
using namespace engine::input::sdl;

SdlButton::SdlButton() : buttonImage(), GameObject(buttonImage), state(ButtonState::MOUSE_OUT),
clipClicked(), clipOut(), clipOver()
{}

SdlButton::SdlButton(const engine::graph::sdl::SdlImage& buttonImage, const SDL_Rect& clipOut,
	const SDL_Rect& clipOver, const SDL_Rect& clipClicked)
{
	SetImage(buttonImage, clipOut, clipOver, clipClicked);
}

SdlButton::~SdlButton()
{}

void SdlButton::LoadMedia()
{}

void SdlButton::SetImage(const engine::graph::sdl::SdlImage& newButtonImage, const SDL_Rect& newClipOut,
	const SDL_Rect& newClipOver, const SDL_Rect& newClipClicked)
{
	this->buttonImage = newButtonImage;
	this->clipOut = newClipOut;
	this->clipOver = newClipOver;
	this->clipClicked = newClipClicked;

	switch (state)
	{
	case game::sdl::ButtonState::CLICKED:
		buttonImage.configuration.clip = clipClicked;
		break;
	case game::sdl::ButtonState::HOLD:
		buttonImage.configuration.clip = clipClicked;
		break;
	case game::sdl::ButtonState::MOUSE_OVER:
		buttonImage.configuration.clip = clipOver;
		break;
	case game::sdl::ButtonState::MOUSE_OUT:
		buttonImage.configuration.clip = clipOut;
		break;
	}
}

void SdlButton::HandleInput(const engine::input::Input& input)
{
	const SdlInput& sdlInput = dynamic_cast<const SdlInput&>(input);

	if (&sdlInput)
	{
		switch (state)
		{
		case ButtonState::CLICKED:
			ClickedHandle(sdlInput);
			break;
		case ButtonState::HOLD:
			HoldHandle(sdlInput);
			break;
		case ButtonState::MOUSE_OUT:
			MouseOutHandle(sdlInput);
			break;
		case ButtonState::MOUSE_OVER:
			MouseOverHandle(sdlInput);
			break;
		}
	}
}

bool SdlButton::MouseOver(const SDL_Point& mouse) const
{
	return (buttonImage.configuration.position.x <= mouse.x &&
		mouse.x < buttonImage.configuration.position.x + buttonImage.configuration.dimension.w &&
		buttonImage.configuration.position.y <= mouse.y &&
		mouse.y < buttonImage.configuration.position.y + buttonImage.configuration.dimension.h);
}

void SdlButton::ClickedHandle(const SdlInput& i)
{
	if (i == SDL_EventType::SDL_MOUSEMOTION)
	{
		if (MouseOver({ i.Event().motion.x, i.Event().motion.y }))
		{
			buttonImage.configuration.clip = clipOver;
			state = ButtonState::MOUSE_OVER;
		}
		else
		{
			buttonImage.configuration.clip = clipOut;
			state = ButtonState::MOUSE_OUT;
		}
	}
	else if (i == SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		buttonImage.configuration.clip = clipClicked;
		state = ButtonState::HOLD;
	}
}

void SdlButton::HoldHandle(const SdlInput& i)
{
	if (i == SDL_EventType::SDL_MOUSEMOTION)
	{
		if (!MouseOver({ i.Event().motion.x, i.Event().motion.y }))
		{
			buttonImage.configuration.clip = clipOut;
			state = ButtonState::MOUSE_OUT;
		}
	}
	else if (i == SDL_EventType::SDL_MOUSEBUTTONUP)
	{
		buttonImage.configuration.clip = clipOver;
		state = ButtonState::CLICKED;
	}
}

void SdlButton::MouseOverHandle(const SdlInput& i)
{
	if (i == SDL_EventType::SDL_MOUSEMOTION)
	{
		if (!MouseOver({ i.Event().motion.x, i.Event().motion.y }))
		{
			buttonImage.configuration.clip = clipOut;
			state = ButtonState::MOUSE_OUT;
		}
	}
	else if (i == SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		buttonImage.configuration.clip = clipClicked;
		state = ButtonState::HOLD;
	}
}

void SdlButton::MouseOutHandle(const engine::input::sdl::SdlInput& i)
{
	if (i == SDL_EventType::SDL_MOUSEMOTION)
	{
		if (MouseOver({ i.Event().motion.x, i.Event().motion.y }))
		{
			buttonImage.configuration.clip = clipOver;
			state = ButtonState::MOUSE_OVER;
		}
	}
}
