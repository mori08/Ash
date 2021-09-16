#include"MyLibrary/MyLibrary.hpp"


void Main()
{
	// アセット管理
	Ash::registerAsset(U"asset/");

	while (System::Update())
	{
		Ash::showFPS();
	}
}