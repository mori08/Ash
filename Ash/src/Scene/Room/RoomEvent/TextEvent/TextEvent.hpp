#pragma once

#include "../RoomEvent.hpp"

namespace Ash
{
	/// <summary>
	/// 画面下部に文字列を表示するイベント
	/// </summary>
	class TextEvent : public RoomEvent
	{
	private:

		// 表示するテキストのリスト
		std::list<String> m_textList;

		// 表示できるテキストの長さ
		double m_drawAbleLength;

	public:

		/// <summary>
		/// 文字列を1つだけ表示する
		/// </summary>
		/// <param name="text"> テキスト </param>
		TextEvent(const String& text);

		/// <summary>
		/// 文字列を複数表示する
		/// </summary>
		/// <param name="text"> テキストのリスト </param>
		TextEvent(const Array<String>& textList);

	private:

		bool update() override;

		void draw() const override;

	};
}