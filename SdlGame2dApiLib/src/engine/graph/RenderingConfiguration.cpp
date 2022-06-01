#include "RenderingConfiguration.h"
using namespace engine::graph::sdl;

Rotation::Rotation() : center({ 0, 0 }), flip(SDL_FLIP_NONE), angle(0.0) {}

Rotation::Rotation(double newAngle, SDL_Point newCenter, SDL_RendererFlip newFlip) : 
	angle(newAngle),
	center({ newCenter.x, newCenter.y }),
	flip(newFlip)
{}

RenderingConfiguration::RenderingConfiguration() :
	position({ 0, 0 }), dimension(), clip({ 0, 0, 0, 0 }), rotation()
{}

RenderingConfiguration::RenderingConfiguration(const SDL_Point& position, const Dimension2D& dimension,
	const SDL_Rect& clip, const Rotation& rotation) :
	position(position), dimension(dimension), clip(clip), rotation(rotation)
{}

RenderingConfiguration::RenderingConfiguration(SDL_Texture* pTexture)
	: position({ 0, 0 }), dimension(), clip(), rotation()
{
	AutoConfigure(pTexture);
}

RenderingConfiguration::RenderingConfiguration(const std::shared_ptr<SDL_Texture>& pTexture)
	: position({ 0, 0 }), dimension(), clip(), rotation()
{
	AutoConfigure(pTexture);
}

void RenderingConfiguration::AutoConfigure(SDL_Texture* pTexture)
{
	int w = 0, h = 0;
	SDL_QueryTexture(pTexture, NULL, NULL, &w, &h);
	position = { 0, 0 };
	dimension = { w, h };
	clip = { 0, 0, w, h };
}

void RenderingConfiguration::AutoConfigure(const std::shared_ptr<SDL_Texture>& pTexture)
{
	AutoConfigure(pTexture.get());
}

void RenderingConfiguration::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void RenderingConfiguration::SetPosition(const SDL_Point& p)
{
	position.x = p.x;
	position.y = p.y;
}

SDL_Point RenderingConfiguration::Position() const
{
	return position;
}

void RenderingConfiguration::SetDimensions(int w, int h)
{
	if (w < 0 || h < 0)
		throw std::logic_error("Invalid values to image's dimension!");
	dimension = { w, h };
}

Dimension2D RenderingConfiguration::Dimension() const
{
	return dimension;
}

void RenderingConfiguration::SetClip(int x, int y, int w, int h)
{
	SetClip({ x, y, w, h });
}

void RenderingConfiguration::SetClip(const SDL_Rect& c)
{
	if (c.x < 0 || c.y < 0 || c.w < 0 || c.h < 0)
		throw std::logic_error("Try to pass Negatives values to Image Clip!");

	clip = c;
}

SDL_Rect  RenderingConfiguration::GetClip() const { return clip; }

void RenderingConfiguration::Rotate(const Rotation& r)
{
	rotation = r;
}

Rotation RenderingConfiguration::GetRotation() const
{
	return rotation;
}