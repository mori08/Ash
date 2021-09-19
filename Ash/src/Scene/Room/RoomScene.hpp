#pragma once

#include "../Scene.hpp"
#include "RoomPlayer/RoomPlayer.hpp"

namespace Ash
{
	/// <summary>
	/// 部屋の探索シーン
	/// </summary>
	class RoomScene : public MyApp::Scene
	{
	private:

		RoomPlayer m_player;

	public:

		RoomScene(const InitData& init);

	private:

		void update() override;

		void draw() const override;

	private:

		/// <summary>
		/// プレイヤーの更新
		/// </summary>
		void updatePlayer();

	};
}