#include "GameScene.hpp"

namespace Ash
{
	GameScene::GameScene(const InitData& init)
		: IScene(init)
	{
	}


	void GameScene::update()
	{
	}


	void GameScene::draw() const
	{
		getData().gameManager.draw();
	}
}
