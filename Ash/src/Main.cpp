#include"MyLibrary/MyLibrary.hpp"
#include"Config/Config.hpp"


void Main()
{
	// ウィンドウの設定
	Window::Resize(Ash::Config::get<Size>(U"Window.size"));
	Window::SetTitle(Ash::Config::get<String>(U"Window.name"));

	// アセット管理
	Ash::registerAsset(U"asset/");

	while (System::Update())
	{
		Ash::showFPS();
	}
}