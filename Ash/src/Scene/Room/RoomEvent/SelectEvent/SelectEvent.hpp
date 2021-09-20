#pragma once

#include "../RoomEvent.hpp"
#include "../../../../ButtonSet/ButtonSet.hpp"

namespace Ash
{
	/// <summary>
	/// �I������\������C�x���g
	/// </summary>
	class SelectEvent : public RoomEvent
	{
	private:

		// ���╶
		String m_text;

		// �\���ł���e�L�X�g�̒���
		double m_drawAbleLength;

		// �{�^���̊Ǘ�
		ButtonSet m_buttonSet;

	public:

		SelectEvent(const String& text, std::function<void()> yesFunc, std::function<void()> noFunc);

	private:

		bool update() override;

		void draw() const override;

	};
}