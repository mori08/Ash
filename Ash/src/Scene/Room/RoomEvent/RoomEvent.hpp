#pragma once

#include<Siv3D.hpp>

namespace Ash
{
	/// <summary>
	/// Room�V�[���ł̃C�x���g�̊��N���X
	/// </summary>
	class RoomEvent
	{
	public:

		virtual bool update() = 0;

		virtual void draw() const = 0;

	};
}