#include "SdlGameObject.h"
using namespace game::sdl;

SdlGameObject::SdlGameObject() : sdlImage(), sdlSoundEffect(), sdlMusic(),
	game::GameObject(sdlImage, sdlSoundEffect, sdlMusic)
{}

SdlGameObject::~SdlGameObject()
{}

void SdlGameObject::SetImage(const engine::graph::sdl::SdlImage& newImage)
{
	sdlImage = newImage;
	image = sdlImage;
}

void SdlGameObject::SetSoundEffect(const engine::audio::sdl::SdlSoundEffect& newSoundEffect)
{
	sdlSoundEffect = newSoundEffect;
}

void SdlGameObject::SetSong(const engine::audio::sdl::SdlMusic& newMusic)
{
	sdlMusic = newMusic;
}

engine::graph::sdl::RenderingConfiguration& SdlGameObject::ImageConfigure()
{
	return sdlImage.configuration;
}

const engine::graph::sdl::RenderingConfiguration& SdlGameObject::ImageConfiguration() const
{
	return sdlImage.configuration;
}
