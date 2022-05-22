#ifndef _MAIN_CONTROLLER_
#define _MAIN_CONTROLLER_

#include "GameObject.h"
#include "Scene.h"

namespace game
{
	class MainController : public Controller // TODO Classe deve ser única?
	{
	public:
		explicit MainController(Scene*);
		~MainController();

		void LoadMedia() override;
		void HandleInput(const engine::input::Input&) override;

		void SetScene(Scene* pNewScene) { pScene = pNewScene; }
	private:
		Scene* pScene;
	};

	static MainController mainController(nullptr);
}

#endif // _MAIN_CONTROLLER_