#pragma once

#include"../Scene.hpp"
#include"../../ButtonSet/ButtonSet.hpp"

namespace Ash
{
	/// <summary>
	/// �^�C�g���V�[��
	/// </summary>
	class TitleScene : public MyApp::Scene
	{
	private:

		// �{�^���̊Ǘ�
		ButtonSet m_buttonSet;

		// �J�[�\���̕�
		double m_cursorWidth;

		// �J�[�\���̉��ɏo����̒���
		double m_cursorLineLength;

		// �J�[�\���̉��ɏo��M�̕s�����x
		double m_cursorLineAlpha;

	public:

		TitleScene(const InitData& init);

		void update() override;

		void updateFadeOut(double) override;

		void draw()const override;

	private:

		/// <summary>
		/// ��ʂ̌`�̌���`��
		/// </summary>
		void drawScreen() const;

		/// <summary>
		/// ���̌`�������e��`��
		/// </summary>
		void drawLine() const;

	};
}