#include "GameManager.hpp"
#include "../../../Config/Config.hpp"
#include "../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	void GameManager::load()
	{
		m_camera.setCenter(Vec2::Zero());
		m_camera.setScale(1);

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
		Rect(0, 0, 10, 10).draw(Palette::Red);
	}
}
