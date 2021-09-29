#include "GameManager.hpp"
#include "../../../Config/Config.hpp"
#include "../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	void GameManager::load()
	{
		// StageManager
		String stageName = U"Test"; // Stage名
		const Size stageSize = Config::get<Size>(U"GameScene." + stageName + U".size"); // ステージのマス数
		m_stage.init(stageSize);
		CSVData stageCSV(U"asset/data/stage/" + stageName + U".csv");
		for (const auto& p : getGridPoint(stageSize))
		{
			m_stage.setTerrain(p, stageCSV[p.y][p.x] == U"1");
		}
	}


	void GameManager::update()
	{
	}


	void GameManager::draw() const
	{
		m_stage.drawDebugTerrain();
	}
}
