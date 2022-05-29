#include "RenderingConfiguration.h"
using namespace engine::graph::sdl;

Rotation::Rotation() : center({ 0, 0 }), flip(SDL_FLIP_NONE), angle(0.0) {}

Rotation::Rotation(double newAngle, SDL_Point newCenter, SDL_RendererFlip newFlip) : 
	angle(newAngle),
	center({ newCenter.x, newCenter.y }),
	flip(newFlip)
{}

RenderingConfiguration::RenderingConfiguration() :
	renderQuad({ 0, 0, 0, 0 }), clip({ 0, 0, 0, 0 }), rotation(),
	transparencyColor({ 0, 0xFF, 0xFF })
{}

RenderingConfiguration::RenderingConfiguration(const SDL_Point& position, int width, int height,
	const SDL_Rect& clip, const Rotation& rotation, const SDL_Color& transparencyColor) :
	renderQuad({position.x, position.y, width, height}), clip(clip), rotation(rotation),
	transparencyColor(transparencyColor)
{}

RenderingConfiguration::RenderingConfiguration(SDL_Texture* pTexture, const SDL_Color& transparencyColor)
	: renderQuad(), clip(), rotation(),
	transparencyColor(transparencyColor)
{
	AutoConfigure(pTexture);
}

RenderingConfiguration::RenderingConfiguration(std::shared_ptr<SDL_Texture> pTexture, const SDL_Color& transparencyColor)
	: renderQuad(), clip(), rotation(),
	transparencyColor(transparencyColor)
{
	AutoConfigure(pTexture);
}

void RenderingConfiguration::AutoConfigure(SDL_Texture* pTexture)
{
	int w = 0, h = 0;
	SDL_QueryTexture(pTexture, NULL, NULL, &w, &h);
	renderQuad = { 0, 0, w, h };
	clip = { 0, 0, w, h };
}

void RenderingConfiguration::AutoConfigure(std::shared_ptr<SDL_Texture> pTexture)
{
	AutoConfigure(pTexture.get());
}

void RenderingConfiguration::SetPosition(int x, int y)
{
	renderQuad.x = x;
	renderQuad.y = y;
}

void RenderingConfiguration::SetPosition(const SDL_Point& p)
{
	renderQuad.x = p.x;
	renderQuad.y = p.y;
}

SDL_Point RenderingConfiguration::Position() const
{
	return { renderQuad.x, renderQuad.y };
}

void RenderingConfiguration::SetDimensions(int w, int h)
{
	if (w < 0 || h < 0)
		throw std::logic_error("Invalid values to image's dimension!");
}

SDL_Rect RenderingConfiguration::RenderQuad() const
{
	return renderQuad;
}

void RenderingConfiguration::SetClip(int x, int y, int w, int h)
{
	SetClip({ x, y, w, h });
}

void RenderingConfiguration::SetClip(const SDL_Rect& c)
{
	if (clip.x < 0 || clip.y < 0 || clip.w < 0 || clip.h < 0)
		throw std::logic_error("Negatives values in Clip!");

	clip = c;
}

SDL_Rect  RenderingConfiguration::GetClip() const { return clip; }

void RenderingConfiguration::Rotate(const Rotation& r)
{
	rotation = r;
}

Rotation  RenderingConfiguration::GetRotation() const
{
	return rotation;
}