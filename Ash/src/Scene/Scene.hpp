#pragma once

#include "Game/Manager/GameManager.hpp"

namespace Ash
{
	// シーンの名前
	enum class SceneName
	{
		TITLE, // タイトル
		ROOM,  // 部屋探索

		LOAD_GAME, // ゲームのロード
		GAME       // ゲーム
	};

	// シーン間で共有されるデータ
	struct ShareData
	{
		GameManager gameManager;
	};

	// シーン管理
	using MyApp = SceneManager<SceneName, ShareData>;
}