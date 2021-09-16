#pragma once

#include"Button/Button.hpp"

namespace Ash
{
	/// <summary>
	/// Button�̃��X�g�������X�V�E�폜���s��
	/// </summary>
	class ButtonSet
	{
	private:

		// �Ǘ����Ă���{�^���̘A�z�z��
		std::unordered_map<String, Button> m_buttonMap;

		// �I�𒆂̃{�^���̖��O
		String m_selectedButtonName;

	public:

		/// <summary>
		/// �{�^���̓o�^
		/// </summary>
		/// <param name="button"> �{�^�� </param>
		void registerButton(const Button& button);

		/// <summary>
		/// �I�𒆂̃{�^���̕ύX
		/// </summary>
		/// <param name="name"> �{�^���̖��O </param>
		void setSelectedButton(const String& name);

		/// <summary>
		/// �{�^�����������Ƃ��̏����̐ݒ�
		/// </summary>
		/// <param name="name">        �{�^���̖��O     </param>
		/// <param name="onClickFunc"> �������Ƃ��̏��� </param>
		void setOnClickFunc(const String& name, std::function<void()> onClickFunc);

		/// <summary>
		/// �{�^���̃��X�g�̎擾
		/// </summary>
		/// <returns> �{�^���̃��X�g </returns>
		const std::unordered_map<String, Button>& getButtonList() const
		{
			return m_buttonMap;
		}

		/// <summary>
		/// �I�𒆂̃{�^���̎擾
		/// </summary>
		/// <returns> �I�𒆂̃{�^�� </returns>
		const Button& getSelectedButton() const;

		/// <summary>
		/// �{�^���̑I���y�у{�^���������ꂽ�Ƃ��̏����̌Ăяo��
		/// </summary>
		/// <param name="basePos"> ����W </param>
		/// <returns> �I�����Ă���{�^�����ύX���ꂽ�Ƃ� true , �����łȂ��Ƃ� false </returns>
		/// <remarks>
		/// ���͂ɉ������{�^���I���̕ύX��
		/// ����L�[�������ꂽ�Ƃ����̃{�^����OnClick�֐����Ăт܂�
		/// 1�t���[����2�x�ȏ�g��Ȃ��ł��������B
		/// </remarks>
		bool update(const Point& basePos = Point::Zero());

	};
}