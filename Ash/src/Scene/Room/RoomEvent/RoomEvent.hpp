#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	/// <summary>
	/// Roomシーンでのイベントの基底クラス
	/// </summary>
	class RoomEvent
	{
	public:

		virtual bool update() = 0;

		virtual void draw() const = 0;

	};
}