#ifndef _GAME_OBJECT_
#define _GAME__OBJECT_

#include "engine/graph/Image.h"
#include "engine/input/Controllable.h"
#include "engine/input/Input.h"

namespace game
{
	struct GameObject : public engine::input::Controllable
	{
		explicit GameObject(engine::graph::Image& i) : Controllable(), image(i) {}
		virtual ~GameObject() {}

		engine::graph::Image& image;
		virtual void HandleInput(const engine::input::Input&) = 0;

		GameObject(const GameObject&); // TODO Como será feita a cópia da imagem?
		GameObject& operator=(const GameObject&); // TODO Como será feita a cópia da imagem?
	};
}

#endif // _GAME_OBJECT
