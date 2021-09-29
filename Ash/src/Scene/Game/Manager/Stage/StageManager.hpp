#pragma once

#include<Siv3D.hpp>

/*
	注) 2種類の座標を以下の表現で使い分ける.
	Vec2  pixel  -> ピクセル座標 : 当たり判定や描画に使用
	Point square -> マス座標     : 障害物の管理や経路探索に使用
*/

namespace Ash
{
	/// <summary>
	/// GameSceneでの地形について管理
	/// </summary>
	class StageManager
	{
	private:

		// 地形のマス座標でのサイズ
		Size m_size;

		// 地形 trueのとき障害物あり
		Array<bool> m_terrain;

	public:

		/* 座標変換 */

		/// <summary>
		/// 1マスの一辺の長さ(ピクセル)の取得
		/// </summary>
		/// <returns> 1マスの一辺の長さ(ピクセル) </returns>
		static double squareSize();

		/// <summary>
		/// ピクセル座標からマス座標に変換
		/// </summary>
		/// <param name="pixel"> ピクセル座標 </param>
		/// <returns>
		/// マス座標
		/// </returns>
		Point pixelToSquare(const Vec2& pixel) const
		{
			return Floor((pixel / squareSize())).asPoint();
		}

		/// <summary>
		/// マス座標からピクセル座標に変換
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <returns>
		/// マスの中心のピクセル座標
		/// </returns>
		Vec2 squareToPixel(const Point& square) const
		{
			return squareSize() * (Vec2::One() * square + Vec2::One() / 2.0);
		}

		/// <summary>
		/// 整数値をそれに対応するマス座標に変換
		/// </summary>
		/// <param name="integer"> 整数値 </param>
		/// <returns>
		/// マス座標
		/// </returns>
		Point integerToSquare(int32 integer) const
		{
			return Point(integer % m_size.x, integer / m_size.x);
		}

		/// <summary>
		/// マス座標をそれに対応する整数値に変換
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <returns>
		/// マス座標に対応する整数値
		/// </returns>
		int32 squareToInteger(const Point& square) const
		{
			return square.x + m_size.x * square.y;
		}

		/// <summary>
		/// ピクセル座標をそれに対応する整数値に変換
		/// </summary>
		/// <param name="pixel"> ピクセル座標 </param>
		/// <returns>
		/// ピクセル座標に対応する整数値
		/// </returns>
		int32 pixelToInteger(const Vec2& pixel) const
		{
			return squareToInteger(pixelToSquare(pixel));
		}

		/// <summary>
		/// 整数値をそれに対応するマスの中心ピクセル座標に変換
		/// </summary>
		/// <param name="integer"> 整数値 </param>
		/// <returns>
		/// 整数値に対応するマスの中心ピクセル座標
		/// </returns>
		Vec2 integerToPixel(int32 integer) const
		{
			return squareToPixel(integerToSquare(integer));
		}

	public:

		/* LoadGameSceneで使用 */

		/// <summary>
		/// 初期化
		/// </summary>
		/// <param name="size"> 地形のマス座標でのサイズ </param>
		void init(const Size& size);

		/// <summary>
		/// 地形を設定する
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <param name="wall"  > trueのとき障害物の設置, falseのとき障害物を排除 </param>
		void setTerrain(const Point& square, bool wall);

	public:

		/* GameSceneで使用 */

		/// <summary>
		/// 指定されたマス座標が行動可能か
		/// </summary>
		/// <param name="square"> マス座標 </param>
		/// <returns> ステージ外であるときや障害物があるとき false , それ以外のとき true </returns>
		bool isWalkAble(const Point& square) const;

		/// <summary>
		/// 指定されたピクセル座標が行動可能か
		/// </summary>
		/// <param name="pixel"> ピクセル座標 </param>
		/// <returns> ステージ外であるときや障害物があるとき false , それ以外のとき true </returns>
		bool isWalkAble(const Vec2& pixel) const
		{
			return isWalkAble(pixelToSquare(pixel));
		}

		/// <summary>
		/// デバッグ用の地形の描画
		/// </summary>
		void drawDebugTerrain() const;

	};
}