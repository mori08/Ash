#pragma once

#include "../Scene.hpp"
#include "RoomPlayer/RoomPlayer.hpp"
#include "RoomEvent/RoomEvent.hpp"

namespace Ash
{
	/// <summary>
	/// �����̒T���V�[��
	/// </summary>
	class RoomScene : public MyApp::Scene
	{
	private:

		// �v���C���[
		RoomPlayer m_player;

		// �C�x���g
		std::list<std::unique_ptr<RoomEvent>> m_eventList;

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

		/// <summary>
		/// ���̕`��
		/// </summary>
		void drawLight() const;

	};
}