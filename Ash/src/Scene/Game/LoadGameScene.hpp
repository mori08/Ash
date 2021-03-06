#pragma once

#include "../Load/LoadScene.hpp"

namespace Ash
{
	/// <summary>
	/// GameManagerの読み込みを行うシーン
	/// </summary>
	class LoadGameScene : public LoadScene
	{
	public:

		LoadGameScene(const InitData& init);

	};
}