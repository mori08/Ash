#include "StageManager.hpp"
#include "../../../../Config/Config.hpp"
#include "../../../../MyLibrary/MyLibrary.hpp"

namespace Ash
{
	double StageManager::squareSize()
	{
		static const double SQUARE_SIZE = Config::get<double>(U"GameScene.squareSize");
		return SQUARE_SIZE;
	}


	void StageManager::load()
	{
		// ステージ名
		String stageName = U"Test";

		// ステージのマス数の設定
		m_size = Config::get<Size>(U"GameScene." + stageName + U".size");;
		m_terrain = Array<bool>(m_size.x * m_size.y, false);

		// CSVファイルの読み込み -> 地形の設定
		CSVData stageCSV(U"asset/data/stage/" + stageName + U".csv");
		for (const auto& p : getGridPoint(m_size))
		{
			m_terrain[squareToInteger(p)] = stageCSV[p.y][p.x] == U"1";
		}
	}


	void StageManager::setTerrain(const Point& square, bool wall)
	{
		m_terrain[squareToInteger(square)] = wall;
	}


	bool StageManager::isWalkAble(const Point& square) const
	{
		if (square.x < 0 || square.x >= m_size.x) { return false; }
		if (square.y < 0 || square.y >= m_size.y) { return false; }
		return !m_terrain[squareToInteger(square)];
	}


	void StageManager::drawDebugTerrain() const
	{
		for (const auto& p : getGridPoint(m_size))
		{
			RectF(squareSize() * p, squareSize())
				.draw(isWalkAble(p) ? MyWhite : MyBlack)
				.drawFrame(2, MyBlack);
		}
	}
}
