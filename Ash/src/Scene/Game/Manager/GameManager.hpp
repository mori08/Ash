#pragma once

#include"Stage/StageManager.hpp"

namespace Ash
{
	class GameManager
	{
	private:

		StageManager m_stage;

	public:

		/// <summary>
		/// StageManager�̎擾
		/// </summary>
		/// <returns> m_stage </returns>
		StageManager& stage()
		{
			return m_stage;
		}

	public:

		/// <summary>
		/// �������ƃX�e�[�W�̓ǂݍ���
		/// </summary>
		void load();

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw() const;

	};
}