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


	void StageManager::init(const Size& size)
	{
		m_size = size;
		m_terrain = Array<bool>(m_size.x * m_size.y, false);
	}


	void StageManager::setTerrain(const Point& square, bool wall)
	{
		m_terrain[squareToInteger(square)] = wall;
	}


	void StageManager::drawDebugTerrain() const
	{
		for (const auto& p : getGridPoint(m_size))
		{
			RectF(squareSize() * p, squareSize()).draw(MyBlack);
		}
	}
}
