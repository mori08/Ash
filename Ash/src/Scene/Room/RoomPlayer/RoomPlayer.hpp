#pragma once

#include "../../../SliceTexture/SliceTexture.hpp"

namespace Ash
{
	class RoomPlayer
	{
	private:

		// 画像とアニメーション
		SliceTexture m_sliceTexture;

		// x座標
		double m_x;

		// 歩いて進む目的x座標
		double m_goalX;

	public:

		/// <param name="x"> 初期x座標 </param>
		RoomPlayer(double x);

	public:

		/// <summary>
		/// 更新
		/// </summary>
		void update();

		/// <summary>
		/// 描画
		/// </summary>
		void draw()const;

		/// <summary>
		/// 歩いての移動を開始
		/// </summary>
		/// <param name="x"> 移動先のx座標 </param>
		void walk(double x);

		/// <summary>
		/// x座標の取得
		/// </summary>
		/// <returns> x座標 </returns>
		double getX() const
		{
			return m_x;
		}

	};
}