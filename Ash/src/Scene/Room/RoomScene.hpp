#pragma once

#include "../Scene.hpp"
#include "RoomPlayer/RoomPlayer.hpp"
#include "RoomEvent/RoomEvent.hpp"

namespace Ash
{
	/// <summary>
	/// 部屋の探索シーン
	/// </summary>
	class RoomScene : public MyApp::Scene
	{
	private:

		// プレイヤー
		RoomPlayer m_player;

		// イベント
		std::unique_ptr<RoomEvent> m_event;

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