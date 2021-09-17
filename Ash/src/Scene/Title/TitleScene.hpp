#pragma once

#include"../Scene.hpp"
#include"../../ButtonSet/ButtonSet.hpp"

namespace Ash
{
	/// <summary>
	/// タイトルシーン
	/// </summary>
	class TitleScene : public MyApp::Scene
	{
	private:

		// ボタンの管理
		ButtonSet m_buttonSet;

		// カーソルの幅
		double m_cursorWidth;

		// カーソルの横に出る線の長さ
		double m_cursorLineLength;

		// カーソルの横に出る閃の不透明度
		double m_cursorLineAlpha;

	public:

		TitleScene(const InitData& init);

		void update() override;

		void updateFadeOut(double) override;

		void draw()const override;

	private:

		/// <summary>
		/// 画面の形の光を描画
		/// </summary>
		void drawScreen() const;

		/// <summary>
		/// 線の形をした影を描画
		/// </summary>
		void drawLine() const;

	};
}