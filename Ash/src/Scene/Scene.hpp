#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	// �V�[���̖��O
	enum class SceneName
	{
		TITLE, // �^�C�g��
		ROOM   // �����T��
	};

	// �V�[���Ԃŋ��L�����f�[�^
	struct ShareData
	{
		
	};

	// �V�[���Ǘ�
	using MyApp = SceneManager<SceneName, ShareData>;
}