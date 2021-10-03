#include "GameManager.hpp"
#include "../../../Config/Config.hpp"
#include "../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	void GameManager::load()
	{
		m_camera = Camera2D(Vec2::Zero(), 1, Camera2DParameters::MouseOnly());

		m_stage.load();
	}


	void GameManager::update()
	{
		m_camera.update();
	}


	void GameManager::draw() const
	{
		{
			const auto t = m_camera.createTransformer();
			m_stage.drawDebugTerrain();
			m_camera.draw();
		}
	}
}
