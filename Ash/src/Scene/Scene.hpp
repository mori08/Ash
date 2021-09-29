#pragma once

#include "Game/Manager/GameManager.hpp"

namespace Ash
{
	// �V�[���̖��O
	enum class SceneName
	{
		TITLE, // �^�C�g��
		ROOM,  // �����T��

		LOAD_GAME, // �Q�[���̃��[�h
		GAME       // �Q�[��
	};

	// �V�[���Ԃŋ��L�����f�[�^
	struct ShareData
	{
		GameManager gameManager;
	};

	// �V�[���Ǘ�
	using MyApp = SceneManager<SceneName, ShareData>;
}