#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	/// <summary>
	/// Stage�ɔz�u����u���b�N
	/// </summary>
	class Block
	{
	private:

		// �u���b�N�͈̔�
		RectF m_rect;

	public:

		/// <param name="rect"> �u���b�N�͈̔� </param>
		Block(const RectF& rect);

	public:

		/// <summary>
		/// �X�V
		/// </summary>
		virtual void update() {}

		/// <summary>
		/// �`��
		/// </summary>
		virtual void draw() const;

		/// <summary>
		/// �폜�ł��邩������
		/// </summary>
		/// <returns> true �Ȃ�폜 </returns>
		virtual bool isEraseAble() const
		{
			return false;
		}

		/// <summary>
		/// ���̒����`�ƌ������Ă��邩�ǂ���
		/// </summary>
		/// <param name="another"> ���̒����` </param>
		/// <returns> �������Ă���Ƃ� true, �����łȂ��Ƃ� false </returns>
		bool intersects(const RectF& another);

	};
}