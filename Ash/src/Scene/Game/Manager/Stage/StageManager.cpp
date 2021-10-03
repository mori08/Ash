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
		m_size = Config::get<Size>(U"GameScene." + stageName + U".size");
		const int32 N = m_size.x * m_size.y; // マス数
		m_terrain = Array<bool>(N, false);

		// CSVファイルの読み込み -> 地形の設定
		CSVData stageCSV(U"asset/data/stage/" + stageName + U".csv");
		for (const auto& p : getGridPoint(m_size))
		{
			m_terrain[squareToInteger(p)] = stageCSV[p.y][p.x] == U"1";
		}

		// 角の算出
		std::set<int32> cornerSet;
		static const Array<Point> CORNER_DIRECTION = Array<Point>{ Point(+1,+1),Point(+1,-1),Point(-1,-1),Point(-1,+1) };
		for (int32 i : Range(0, N - 1))
		{
			Point square = integerToSquare(i);

			// 障害物のあるマスならスキップ
			if (!isWalkAble(square)) { continue; }

			for (const auto& d : CORNER_DIRECTION)
			{
				// 角になってるならリストに追加
				if (!isWalkAble(square + d) && isWalkAble(square + Point(d.x, 0)) && isWalkAble(square + Point(0, d.y)))
				{
					cornerSet.insert(i);
					break;
				}
			}
		}

		// 辺の作成
		m_path     = Array<Array<int32>> (N);
		m_distance = Array<Array<double>>(N, Array<double>(N, Inf<double>));
		for (int32 i : Range(0, N - 1)) { m_path[i] = Array<int32>(N, i); }
		for (const Point& tl : getGridPoint(m_size))
		{
			if (!isWalkAble(tl)) { continue; }

			// 右方向
			for (Point sq = tl; isWalkAble(sq); sq.x++) { makeEdge(sq, tl); }

			// 下方向
			for (Point sq = tl; isWalkAble(sq); sq.y++) { makeEdge(sq, tl); }

			for (const Point& br : getGridPoint(getRectFromTwoPoint(tl + Point::One(), m_size - Point::One())))
			{
				if (isWalkAble(br)
					&& m_path[squareToInteger(tl)][squareToInteger(br + Point::Up())  ] != squareToInteger(tl)
					&& m_path[squareToInteger(tl)][squareToInteger(br + Point::Left())] != squareToInteger(tl)
					)
				{
					makeEdge(tl, br);
					makeEdge(Point(tl.x, br.y), Point(br.x, tl.y));
				}
			}
		}

		// 各マスから行くことのできる角を探索
		Array<Array<int32>> nodeToCorner(N);
		for (int32 i : Range(0, N - 1))
		{
			if (!isWalkAble(i)) { continue; }
			for (int32 c : cornerSet)
			{
				if (m_path[i][c] != i) { nodeToCorner[i].emplace_back(c); }
			}
		}

		// 角グラフでワーシャルフロイドを用いた最短経路探索
		for (int32 k : cornerSet)
		{
			for (int32 i : cornerSet)
			{
				for (int32 j : cornerSet)
				{
					if (m_distance[i][j] > m_distance[i][k] + m_distance[k][j])
					{
						m_distance[i][j] = m_distance[i][k] + m_distance[k][j];
						m_path    [i][j] = m_path    [i][k];
					}
				}
			}
		}

		// 各マスから各マスへの経路探索
		for (int32 i : Range(0, N - 1))
		{
			if (!isWalkAble(i)) { continue; }
			
			for (int32 j : Range(0, N - 1))
			{
				if (!isWalkAble(j)) { continue; }
				if (i == j || m_path[i][j] != i) { continue; }

				double minDistance = Inf<double>;
				int32  minPath     = i;

				for (int32 cornerI : nodeToCorner[i]) // iの行くことのできる角
				{
					for (int32 cornerJ : nodeToCorner[j]) // jの行くことのできる角
					{
						double distance = m_distance[i][cornerI] + m_distance[cornerI][cornerJ] + m_distance[cornerJ][j];
						if (distance < minDistance)
						{
							minDistance = distance;
							minPath     = cornerI;
						}
					}
				}

				m_distance[i][j] = minDistance;
				m_path    [i][j] = minPath;
			}
		}
	}


	void StageManager::makeEdge(const Point& s1, const Point& s2)
	{
		m_path[squareToInteger(s1)][squareToInteger(s2)] = squareToInteger(s2);
		m_path[squareToInteger(s2)][squareToInteger(s1)] = squareToInteger(s1);

		const double distance = s1.distanceFrom(s2);
		m_distance[squareToInteger(s1)][squareToInteger(s2)] = distance;
		m_distance[squareToInteger(s2)][squareToInteger(s1)] = distance;
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
