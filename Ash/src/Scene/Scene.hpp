#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	// シーンの名前
	enum class SceneName
	{
		TITLE // タイトル
	};

	// シーン間で共有されるデータ
	struct ShareData
	{
		
	};

	// シーン管理
	using MyApp = SceneManager<SceneName, ShareData>;
}