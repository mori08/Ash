#pragma once

#include "../Scene.hpp"

namespace Ash
{
	/// <summary>
	/// •”‰®‚Ì’TõƒV[ƒ“
	/// </summary>
	class RoomScene : public MyApp::Scene
	{
	private:

	public:

		RoomScene(const InitData& init);

	private:

		void update() override;

		void draw() const override;

	};
}