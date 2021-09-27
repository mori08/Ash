#pragma once

#include"Stage/StageManager.hpp"

namespace Ash
{
	class GameManager
	{
	private:

		StageManager m_stage;

	public:

		/// <summary>
		/// StageManagerの取得
		/// </summary>
		/// <returns> m_stage </returns>
		StageManager& stage()
		{
			return m_stage;
		}

	public:

		/// <summary>
		/// 初期化とステージの読み込み
		/// </summary>
		void load();

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw() const;

	};
}