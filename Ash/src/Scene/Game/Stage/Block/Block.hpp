#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	/// <summary>
	/// Stageに配置するブロック
	/// </summary>
	class Block
	{
	private:

		// ブロックの範囲
		RectF m_rect;

	public:

		/// <param name="rect"> ブロックの範囲 </param>
		Block(const RectF& rect);

	public:

		/// <summary>
		/// 更新
		/// </summary>
		virtual void update() {}

		/// <summary>
		/// 描画
		/// </summary>
		virtual void draw() const;

		/// <summary>
		/// 削除できるかを示す
		/// </summary>
		/// <returns> true なら削除 </returns>
		virtual bool isEraseAble() const
		{
			return false;
		}

		/// <summary>
		/// 他の長方形と交差しているかどうか
		/// </summary>
		/// <param name="another"> 他の長方形 </param>
		/// <returns> 交差しているとき true, そうでないとき false </returns>
		bool intersects(const RectF& another);

	};
}