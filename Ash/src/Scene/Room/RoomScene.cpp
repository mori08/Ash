#include "RoomScene.hpp"
#include "../../MyLibrary/MyLibrary.hpp"
#include "../../Config/Config.hpp"

// イベント
#include "RoomEvent/TextEvent/TextEvent.hpp"
#include "RoomEvent/SelectEvent/SelectEvent.hpp"

namespace Ash
{
	RoomScene::RoomScene(const InitData& init)
		: IScene(init)
		, m_player(Config::get<int32>(U"RoomScene.playerInitX"))
	{
		m_eventList.emplace_back(std::make_unique<TextEvent>(Array<String>{U"a", U"b", U"c"}));

		m_eventList.emplace_back(std::make_unique<SelectEvent>(
			U"Test Test Test Test Test",
			[this]() { Print << U"Hello"; m_eventList.pop_front(); },
			[this]() { Print << U"World"; m_eventList.pop_front(); }
		));
	}


	void RoomScene::update()
	{
		if (m_eventList.empty()) 
		{ 
			updatePlayer();
		}
		else
		{
			if (m_eventList.front()->update()) { m_eventList.pop_front(); }
		}
	}


	void RoomScene::draw() const
	{
		// 背景画像を表示する座標
		static Point BACKGROUND_POS=Config::get<Point>(U"RoomScene.backgroundPos");
		// 上側の黒
		static Rect BLACK_RECT_1 = Config::get<Rect>(U"RoomScene.blackRect1");
		// 下側の黒
		static Rect BLACK_RECT_2 = Config::get<Rect>(U"RoomScene.blackRect2");

		Scene::Rect().draw(MyWhite);
		TextureAsset(U"RoomBackground").draw(BACKGROUND_POS);

		m_player.draw();

		BLACK_RECT_1.draw(MyBlack);
		BLACK_RECT_2.draw(MyBlack);

		if (!m_eventList.empty()) { m_eventList.front()->draw(); }
	}


	void RoomScene::updatePlayer()
	{
		// 部屋を描画する範囲
		static const Rect ROOM_REGION = Config::get<Rect>(U"RoomScene.roomRegion");

		if (ROOM_REGION.leftClicked())
		{
			m_player.walk(Cursor::PosF().x);
		}

		m_player.update();
	}
}
