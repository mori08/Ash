#include "TextEvent.hpp"
#include "../../../../Config/Config.hpp"
#include "../../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	TextEvent::TextEvent(const String& text)
		: m_drawAbleLength(0)
	{
		m_textList.emplace_back(text);
	}

	TextEvent::TextEvent(const Array<String>& textList)
		: m_drawAbleLength(0)
	{
		for (const auto& text : textList)
		{
			m_textList.emplace_back(text);
		}
	}

	bool TextEvent::update()
	{
		// 1秒間の間に表示する文字数
		static const double TEXT_DRAW_SPEED = Config::get<double>(U"RoomScene.Event.Text.drawSpeed");
		// 文字列を表示する範囲
		static const Rect TEXT_REGION = Config::get<Rect>(U"RoomScene.blackRect2");

		if (m_textList.empty()) { return true; }

		m_drawAbleLength += Scene::DeltaTime() * TEXT_DRAW_SPEED;
		
		if (TEXT_REGION.leftClicked())
		{
			if ((size_t)m_drawAbleLength >= m_textList.front().length())
			{
				m_textList.pop_front();
				m_drawAbleLength = 0;
			}
			else
			{
				m_drawAbleLength = (double)m_textList.front().length();
			}
		}
		
		return false;
	}


	void TextEvent::draw() const
	{
		// 文字列を表示する座標
		static const Point TEXT_DRAW_POS = Config::get<Point>(U"RoomScene.Event.textDrawPos");

		if (m_textList.empty()) { return; }

		FontAsset(U"20")(m_textList.front().substr(0, (size_t)m_drawAbleLength))
			.draw(TEXT_DRAW_POS, MyWhite);
	}
}
