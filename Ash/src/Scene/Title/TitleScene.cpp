#include "TitleScene.hpp"
#include "../../Config/Config.hpp"
#include "../../MyLibrary/MyLibrary.hpp"

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
		// �J�[�\���̕`��
		getRectFromCenter
		(
			m_buttonSet.getSelectedButton().getRegion().center().asPoint(),
			Size((int32)m_cursorWidth, buttonSize().y)
		).draw(MyWhite);
		getRectFromCenter
		(
			m_buttonSet.getSelectedButton().getRegion().center().asPoint(),
			Size((int32)m_cursorLineLength, 1)
		).draw(ColorF(MyWhite, m_cursorLineAlpha));

		// �{�^���̕`��
		for (const auto& button : m_buttonSet.getButtonList())
		{
			Color color = (button.first == m_buttonSet.getSelectedButton().getName())
				? MyBlack
				: MyWhite;

			FontAsset(U"20")(button.first)
				.drawAt(button.second.getRegion().center(), color);
		}

		static const Point LOGO_POS = Config::get<Point>(U"TitleScene.logoPos");
		// ���S�̕`��
		TextureAsset(U"TitleLogo").drawAt(LOGO_POS);
	}
}
