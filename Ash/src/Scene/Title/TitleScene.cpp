#include "TitleScene.hpp"
#include "../../Config/Config.hpp"
#include "../../MyLibrary/MyLibrary.hpp"
#include "../../MyPixelShader/MyPixelShader.hpp"

namespace
{
	// �{�^���T�C�Y
	const Size& buttonSize()
	{
		static const Size& size = Ash::Config::get<Size>(U"TitleScene.buttonSize");
		return size;
	}

	// NEWGAME�{�^��
	const Ash::Button& newgameButton()
	{
		static const Ash::Button button = Ash::Config::get<Ash::Button>(U"TitleScene.NewgameButton");
		return button;
	}

	// LOADGAME�{�^��
	const Ash::Button& loadgameButton()
	{
		static const Ash::Button button = Ash::Config::get<Ash::Button>(U"TitleScene.LoadgameButton");
		return button;
	}

	// EXITGAME�{�^��
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
		// �J�[�\���̈ړ��̔�
		static const double CURSOR_MOVE_RATE = Config::get<double>(U"TitleScene.cursorMoveRate");

		// �J�[�\���̕��̕ύX
		internalDividingPoint
		(
			m_cursorWidth,
			buttonSize().x,
			CURSOR_MOVE_RATE
		);

		// �J�[�\���̉��ɏo����̒����̕ύX
		internalDividingPoint
		(
			m_cursorLineLength,
			Scene::Width(),
			CURSOR_MOVE_RATE
		);

		// �J�[�\���̉��ɏo����̕s�����x�̕ύX
		internalDividingPoint
		(
			m_cursorLineAlpha,
			0,
			CURSOR_MOVE_RATE
		);
	}


	void TitleScene::draw() const
	{
		// ���S��`�悷����W
		static const Point LOGO_POS = Config::get<Point>(U"TitleScene.logoPos");

		// �w�i�F
		Scene::Rect().draw(MyBlack);

		drawScreen();
		drawLine();

		// ���S�̕`��
		TextureAsset(U"TitleLogo").drawAt(LOGO_POS);

		// �J�[�\���̕`��
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

		// �{�^���̕`��
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
		// ��ʂ̌`
		static const RoundRect SHAPE = Config::get<RoundRect>(U"TitleScene.Screen.roundRect");
		// ��ʂ̂ڂ���
		static const double BLUR = Config::get<double>(U"TitleScene.Screen.blur");
		// ��ʂ̍L����p�x
		static const double SPREAD_FREQUENCY = Config::get<double>(U"TitleScene.Screen.spreadFrequency");

		// ��ʂ̌`���������̕`��
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
		// ����`�悷��p�x
		static const double FREQUENCY = Config::get<double>(U"TitleScene.Line.frequency");
		// ���̕�
		static const int32 WIDTH = Config::get<int32>(U"TitleScene.Line.width");
		// ���̕s�����x
		static const double ALPHA = Config::get<double>(U"TitleScene.Line.alpha");

		if (randomFrequency(FREQUENCY))
		{
			Rect(0, Random(Scene::Height()), Scene::Width(), WIDTH)
				.draw(ColorF(MyBlack, ALPHA));
		}
	}
}
