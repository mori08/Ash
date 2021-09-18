#include "RoomScene.hpp"
#include "../../MyLibrary/MyLibrary.hpp"
#include "../../Config/Config.hpp"

namespace Ash
{
	RoomScene::RoomScene(const InitData& init)
		: IScene(init)
	{
	}


	void RoomScene::update()
	{
	}


	void RoomScene::draw() const
	{
		// îwåiâÊëúÇï\é¶Ç∑ÇÈç¿ïW
		static Point BACKGROUND_POS=Config::get<Point>(U"RoomScene.backgroundPos");
		// è„ë§ÇÃçï
		static Rect BLACK_RECT_1 = Config::get<Rect>(U"RoomScene.blackRect1");
		// â∫ë§ÇÃçï
		static Rect BLACK_RECT_2 = Config::get<Rect>(U"RoomScene.blackRect2");

		Scene::Rect().draw(MyWhite);
		TextureAsset(U"RoomBackground").draw(BACKGROUND_POS);

		BLACK_RECT_1.draw(MyBlack);
		BLACK_RECT_2.draw(MyBlack);
	}
}
