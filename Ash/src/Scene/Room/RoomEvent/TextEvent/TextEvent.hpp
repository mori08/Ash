#pragma once

#include "../RoomEvent.hpp"

namespace Ash
{
	/// <summary>
	/// ��ʉ����ɕ������\������C�x���g
	/// </summary>
	class TextEvent : public RoomEvent
	{
	private:

		// �\������e�L�X�g�̃��X�g
		std::list<String> m_textList;

		// �\���ł���e�L�X�g�̒���
		double m_drawAbleLength;

	public:

		/// <summary>
		/// �������1�����\������
		/// </summary>
		/// <param name="text"> �e�L�X�g </param>
		TextEvent(const String& text);

		/// <summary>
		/// ������𕡐��\������
		/// </summary>
		/// <param name="text"> �e�L�X�g�̃��X�g </param>
		TextEvent(const Array<String>& textList);

	private:

		bool update() override;

		void draw() const override;

	};
}