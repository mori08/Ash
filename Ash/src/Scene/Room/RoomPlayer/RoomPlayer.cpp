#include "RoomPlayer.hpp"
#include "../../../Config/Config.hpp"

namespace Ash
{
	RoomPlayer::RoomPlayer(double x)
		: m_sliceTexture(U"RoomPlayer", Config::get<Size>(U"RoomScene.Player.textureSize"))
		, m_x(x)
		, m_goalX(x)
	{
		static const Animation WAIT_ANIM = Config::get<Animation>(U"RoomScene.Player.WaitAnim");
		static const Animation WALK_ANIM = Config::get<Animation>(U"RoomScene.Player.WalkAnim");

		m_sliceTexture.setAnimation(U"Wait", WAIT_ANIM);
		m_sliceTexture.setAnimation(U"Walk", WALK_ANIM);
		m_sliceTexture.start(U"Wait");
	}


	void RoomPlayer::update()
	{
		// •à‚­‘¬“x
		const double SPEED = Config::get<double>(U"RoomScene.Player.speed");

		if (Abs(m_goalX - m_x) > SPEED * Scene::DeltaTime())
		{
			m_x += SPEED * Scene::DeltaTime() * (m_goalX - m_x) / Abs(m_goalX - m_x);
		}
		else
		{
			m_x = m_goalX;
			m_sliceTexture.start(U"Wait");
		}

		m_sliceTexture.update();
	}


	void RoomPlayer::draw() const
	{
		const int32 Y = Config::get<int32>(U"RoomScene.Player.y");
		m_sliceTexture.getTexture().drawAt((int32)m_x, Y);
	}


	void RoomPlayer::walk(double x)
	{
		m_goalX = Clamp(x, 1.0 * m_sliceTexture.getSliceSize().x / 2, 1.0 * Scene::Width() - m_sliceTexture.getSliceSize().x / 2);
		m_sliceTexture.startAnotherAnimation(U"Walk");

		m_sliceTexture.mirror(m_goalX > m_x);
	}
}
