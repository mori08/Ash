#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	/// <summary>
	/// {ボタンの範囲,名前,推したときの処理}をまとめる
	/// </summary>
	class Button
	{
	private:

		// 名前
		const String m_name;

		// 範囲
		const Rect m_region;

		// クリックされたときの処理
		std::function<void()> m_onClickFunc;

	public:

		/// <summary>
		/// ボタン
		/// </summary>
		/// <param name="name"  > 名前 </param>
		/// <param name="region"> 範囲 </param>
		Button(const String& name, const Rect& region)
			: m_name(name)
			, m_region(region)
			, m_onClickFunc([](){})
		{
		}

	public:

		/// <summary>
		/// ボタンの名前の取得
		/// </summary>
		/// <returns> ボタンの名前 </returns>
		const String& getName() const
		{
			return m_name;
		}

		/// <summary>
		/// ボタンの範囲の取得
		/// </summary>
		/// <returns> ボタンの範囲 </summary>
		const Rect& getRegion() const
		{
			return m_region;
		}

		/// <summary>
		/// クリックしたときの処理の設定
		/// </summary>
		/// <param name="onClickFunc"> 押したときの処理 </param>
		void setOnClickFunc(const std::function<void()>& onClickFunc)
		{
			m_onClickFunc = onClickFunc;
		}

		/// <summary>
		/// クリックしたときの処理
		/// </summary>
		void onClick() const
		{
			m_onClickFunc();
		}

	};
}