#include "TitleScene.hpp"
#include "../../Config/Config.hpp"
#include "../../MyLibrary/MyLibrary.hpp"
#include "../../MyPixelShader/MyPixelShader.hpp"

namespace
{
	// ボタンサイズ
	const Size& buttonSize()
	{
		static const Size& size = Ash::Config::get<Size>(U"TitleScene.buttonSize");
		return size;
	}

	// NEWGAMEボタン
	const Ash::Button& newgameButton()
	{
		static const Ash::Button button = Ash::Config::get<Ash::Button>(U"TitleScene.NewgameButton");
		return button;
	}

	// LOADGAMEボタン
	const Ash::Button& loadgameButton()
	{
		static const Ash::Button button = Ash::Config::get<Ash::Button>(U"TitleScene.LoadgameButton");
		return button;
	}

	// EXITGAMEボタン
	const Ash::Button& exitgameButton()
	{
		static const Ash::Button button = Ash::Config::get<Ash::Button>(U"TitleScene.ExitgameButton");
		return button;
	}
}

namespace Ash
{
	TitleScene::TitleScene(const InitData& init)
		: IScene(init)
		, m_cursorWidth(Config::get<Size>(U"TitleScene.buttonSize").x)
		, m_cursorLineLength(Scene::Size().x)
		, m_cursorLineAlpha(0)
	{
		m_buttonSet.registerButton(newgameButton());
		m_buttonSet.registerButton(loadgameButton());
		m_buttonSet.registerButton(exitgameButton());

		m_buttonSet.setOnClickFunc(newgameButton().getName(), [this]() {changeScene(SceneName::TITLE); });

		m_buttonSet.setSelectedButton(loadgameButton().getName());
	}


	void TitleScene::update()
	{
		updateFadeOut(0);

		if (m_buttonSet.update())
		{
			m_cursorWidth = 0;
			m_cursorLineLength = 0;
			m_cursorLineAlpha = 1;
		}
	}


	void TitleScene::updateFadeOut(double)
	{
		// カーソルの移動の比
		static const double CURSOR_MOVE_RATE = Config::get<double>(U"TitleScene.cursorMoveRate");

		// カーソルの幅の変更
		internalDividingPoint
		(
			m_cursorWidth,
			buttonSize().x,
			CURSOR_MOVE_RATE
		);

		// カーソルの横に出る線の長さの変更
		internalDividingPoint
		(
			m_cursorLineLength,
			Scene::Width(),
			CURSOR_MOVE_RATE
		);

		// カーソルの横に出る線の不透明度の変更
		internalDividingPoint
		(
			m_cursorLineAlpha,
			0,
			CURSOR_MOVE_RATE
		);
	}


	void TitleScene::draw() const
	{
		// ロゴを描画する座標
		static const Point LOGO_POS = Config::get<Point>(U"TitleScene.logoPos");

		// 背景色
		Scene::Rect().draw(MyBlack);

		drawScreen();
		drawLine();

		// ロゴの描画
		TextureAsset(U"TitleLogo").drawAt(LOGO_POS);

		// カーソルの描画
		getRectFromCenter
		(
			m_buttonSet.getSelectedButton().getRegion().center().asPoint(),
			Size((int32)m_cursorWidth, buttonSize().y)
		).draw(MyBlack);
		getRectFromCenter
		(
			m_buttonSet.getSelectedButton().getRegion().center().asPoint(),
			Size((int32)m_cursorLineLength, 1)
		).draw(ColorF(MyBlack, m_cursorLineAlpha));

		// ボタンの描画
		for (const auto& button : m_buttonSet.getButtonList())
		{
			Color color = (button.first == m_buttonSet.getSelectedButton().getName())
				? MyGray
				: MyBlack;

			FontAsset(U"20")(button.first)
				.drawAt(button.second.getRegion().center(), color);
		}
	}


	void TitleScene::drawScreen() const
	{
		// 画面の形
		static const RoundRect SHAPE = Config::get<RoundRect>(U"TitleScene.Screen.roundRect");
		// 画面のぼかし
		static const double BLUR = Config::get<double>(U"TitleScene.Screen.blur");
		// 画面の広がる頻度
		static const double SPREAD_FREQUENCY = Config::get<double>(U"TitleScene.Screen.spreadFrequency");

		// 画面の形をした光の描画
		SHAPE.drawShadow
		(
			Vec2::Zero(),
			BLUR,
			randomFrequency(SPREAD_FREQUENCY),
			MyGray
		);
	}


	void TitleScene::drawLine() const
	{
		// 線を描画する頻度
		static const double FREQUENCY = Config::get<double>(U"TitleScene.Line.frequency");
		// 線の幅
		static const int32 WIDTH = Config::get<int32>(U"TitleScene.Line.width");
		// 線の不透明度
		static const double ALPHA = Config::get<double>(U"TitleScene.Line.alpha");

		if (randomFrequency(FREQUENCY))
		{
			Rect(0, Random(Scene::Height()), Scene::Width(), WIDTH)
				.draw(ColorF(MyBlack, ALPHA));
		}
	}
}
