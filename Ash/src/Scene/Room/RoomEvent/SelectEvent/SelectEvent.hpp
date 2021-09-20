#pragma once

#include "../RoomEvent.hpp"
#include "../../../../ButtonSet/ButtonSet.hpp"

namespace Ash
{
	/// <summary>
	/// 選択肢を表示するイベント
	/// </summary>
	class SelectEvent : public RoomEvent
	{
	private:

		// 質問文
		String m_text;

		// 表示できるテキストの長さ
		double m_drawAbleLength;

		// ボタンの管理
		ButtonSet m_buttonSet;

	public:

		SelectEvent(const String& text, std::function<void()> yesFunc, std::function<void()> noFunc);

	private:

		bool update() override;

		void draw() const override;

	};
}