#pragma once

#include "../Scene.hpp"

namespace Ash
{
	/// <summary>
	/// 部屋の探索シーン
	/// </summary>
	class RoomScene : public MyApp::Scene
	{
	private:

	public:

		RoomScene(const InitData& init);

	private:

		void update() override;

		void draw() const override;

	};
}