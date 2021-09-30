#include "GameManager.hpp"
#include "../../../Config/Config.hpp"
#include "../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	void GameManager::load()
	{
		m_stage.load();
	}


	void GameManager::update()
	{
	}


	void GameManager::draw() const
	{
		m_stage.drawDebugTerrain();
	}
}
