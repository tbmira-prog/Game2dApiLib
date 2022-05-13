#ifndef _GAME_OBJECT_
#define _GAME__OBJECT_

#include "engine/graph/Image.h"
#include "engine/input/Controllable.h"
#include "engine/input/Input.h"

#include "engine/audio/NullAudio.h"
#include "engine/graph/NullImage.h"

namespace game
{
	struct GameObject : public engine::input::Controllable
	{
		explicit GameObject(engine::graph::Image& image = engine::graph::invisible,
							engine::audio::SoundEffect& soundEffect = engine::audio::silence,
							engine::audio::Song& song = engine::audio::noSong) : Controllable(), image(image), soundEffect(soundEffect), song(song) 
		{}

		virtual ~GameObject() {}

		virtual void HandleInput(const engine::input::Input&) = 0;

		engine::graph::Image& image;
		engine::audio::SoundEffect& soundEffect;
		engine::audio::Song& song;

		//GameObject(const GameObject&) = default;
		//GameObject& operator=(const GameObject&) = default;
	};

	struct StaticGameObject final : public GameObject
	{
		explicit StaticGameObject(engine::graph::Image& i) : GameObject(i) {}
		~StaticGameObject() {}

		void HandleInput(const engine::input::Input&) override {}
	};

	struct Controller : public GameObject // HACK Impedir usuário de alterar a imagem de um controler
	{
		Controller() {}
		virtual ~Controller() {}

		virtual void HandleInput(const engine::input::Input&) override = 0;
	};
}

#endif // _GAME_OBJECT
