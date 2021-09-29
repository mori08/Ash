#pragma once

#include "../Scene.hpp"

namespace Ash
{
	/// <summary>
	/// Game(�V���[�e�B���O)���s���V�[��
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