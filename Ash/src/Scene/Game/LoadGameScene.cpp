#include "LoadGameScene.hpp"

namespace Ash
{
	LoadGameScene::LoadGameScene(const InitData& init)
		: LoadScene(init)
	{
		auto& gameManager = getData().gameManager;

		setLoadThread
		(
			[&gameManager]()
			{
				gameManager.load();
				return SceneName::GAME;
			}
		);
	}
}
