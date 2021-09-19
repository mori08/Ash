#pragma once

#include "../Scene.hpp"
#include "RoomPlayer/RoomPlayer.hpp"

namespace Ash
{
	/// <summary>
	/// �����̒T���V�[��
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
		/// �v���C���[�̍X�V
		/// </summary>
		void updatePlayer();

	};
}