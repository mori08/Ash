#include "SelectEvent.hpp"
#include "../../../../Config/Config.hpp"
#include "../../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	SelectEvent::SelectEvent(const String& text, std::function<void()> yesFunc, std::function<void()> noFunc)
		: m_text(text)
		, m_drawAbleLength(0)
	{
		static const Button YES_BUTTON = Config::get<Button>(U"RoomScene.Event.Text.YesButton");
		static const Button NO_BUTTON = Config::get<Button>(U"RoomScene.Event.Text.NoButton");

		m_buttonSet.registerButton(YES_BUTTON);
		m_buttonSet.registerButton(NO_BUTTON);

		m_buttonSet.setOnClickFunc(YES_BUTTON.getName(), yesFunc);
		m_buttonSet.setOnClickFunc(NO_BUTTON.getName(), noFunc);
	}


	bool SelectEvent::update()
	{
		// 1秒間の間に表示する文字数
		static const double TEXT_DRAW_SPEED = Config::get<double>(U"RoomScene.Event.Text.drawSpeed");
		// 文字列を表示する範囲
		static const Rect TEXT_REGION = Config::get<Rect>(U"RoomScene.blackRect2");

		m_drawAbleLength += Scene::DeltaTime() * TEXT_DRAW_SPEED;

		if ((size_t)m_drawAbleLength >= m_text.length())
		{
			m_buttonSet.update();
		}
		else if (TEXT_REGION.leftClicked())
		{
			m_drawAbleLength = (double)m_text.length();
		}

		return false;
	}


	void SelectEvent::draw() const
	{
		// 文字列を表示する座標
		static const Point TEXT_DRAW_POS = Config::get<Point>(U"RoomScene.Event.textDrawPos");

		FontAsset(U"20")(m_text.substr(0, (size_t)m_drawAbleLength)).draw(TEXT_DRAW_POS, MyWhite);

		if ((size_t)m_drawAbleLength < m_text.length()) { return; }

		for (const auto& itr : m_buttonSet.getButtonList())
		{
			const auto& button = itr.second;
			ColorF color = MyWhite;

			if (button.getName() == m_buttonSet.getSelectedButton().getName())
			{
				color = MyBlack;
				button.getRegion().draw(MyWhite);
			}

			FontAsset(U"20")(button.getName()).drawAt(button.getRegion().center(), color);
		}
	}
}
