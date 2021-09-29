#pragma once

#include "../Scene.hpp"

namespace Ash
{
	/// <summary>
	/// Game(シューティング)を行うシーン
	/// </summary>
	class GameScene : public MyApp::Scene
	{
	public:

		GameScene(const InitData& init);

	public:

		void update() override;

		void draw() const override;

	};
}