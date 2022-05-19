#ifndef _MAIN_CONTROLLER_
#define _MAIN_CONTROLLER_

#include "GameObject.h"
#include "Scene.h"

namespace game
{
	class MainController : public Controller
	{
	public:
		explicit MainController(Scene*);
		~MainController();

		void LoadMedia() override;
		void HandleInput(const engine::input::Input&) override;

	private:
		Scene* pScene;
	};
}

#endif // _MAIN_CONTROLLER_