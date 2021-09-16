#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	/// <summary>
	/// {�{�^���͈̔�,���O,�������Ƃ��̏���}���܂Ƃ߂�
	/// </summary>
	class Button
	{
	private:

		// ���O
		const String m_name;

		// �͈�
		const Rect m_region;

		// �N���b�N���ꂽ�Ƃ��̏���
		std::function<void()> m_onClickFunc;

	public:

		/// <summary>
		/// �{�^��
		/// </summary>
		/// <param name="name"  > ���O </param>
		/// <param name="region"> �͈� </param>
		Button(const String& name, const Rect& region)
			: m_name(name)
			, m_region(region)
			, m_onClickFunc([](){})
		{
		}

	public:

		/// <summary>
		/// �{�^���̖��O�̎擾
		/// </summary>
		/// <returns> �{�^���̖��O </returns>
		const String& getName() const
		{
			return m_name;
		}

		/// <summary>
		/// �{�^���͈̔͂̎擾
		/// </summary>
		/// <returns> �{�^���͈̔� </summary>
		const Rect& getRegion() const
		{
			return m_region;
		}

		/// <summary>
		/// �N���b�N�����Ƃ��̏����̐ݒ�
		/// </summary>
		/// <param name="onClickFunc"> �������Ƃ��̏��� </param>
		void setOnClickFunc(const std::function<void()>& onClickFunc)
		{
			m_onClickFunc = onClickFunc;
		}

		/// <summary>
		/// �N���b�N�����Ƃ��̏���
		/// </summary>
		void onClick() const
		{
			m_onClickFunc();
		}

	};
}