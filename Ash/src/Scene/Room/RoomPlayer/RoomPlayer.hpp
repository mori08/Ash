#pragma once

#include "../../../SliceTexture/SliceTexture.hpp"

namespace Ash
{
	class RoomPlayer
	{
	private:

		// �摜�ƃA�j���[�V����
		SliceTexture m_sliceTexture;

		// x���W
		double m_x;

		// �����Đi�ޖړIx���W
		double m_goalX;

	public:

		/// <param name="x"> ����x���W </param>
		RoomPlayer(double x);

	public:

		/// <summary>
		/// �X�V
		/// </summary>
		void update();

		/// <summary>
		/// �`��
		/// </summary>
		void draw()const;

		/// <summary>
		/// �����Ă̈ړ����J�n
		/// </summary>
		/// <param name="x"> �ړ����x���W </param>
		void walk(double x);

		/// <summary>
		/// x���W�̎擾
		/// </summary>
		/// <returns> x���W </returns>
		double getX() const
		{
			return m_x;
		}

	};
}