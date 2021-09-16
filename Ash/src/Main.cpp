#include"MyLibrary/MyLibrary.hpp"
#include"Config/Config.hpp"


void Main()
{
	// ウィンドウの設定
	Window::Resize(Ash::Config::get<Size>(U"Window.size"));
	Window::SetTitle(Ash::Config::get<String>(U"Window.name"));

	// アセット管理
	Ash::registerAsset(U"asset/");
	for (int32 fontSize = 10; fontSize <= 40; ++fontSize) // フォントサイズ
	{
		FontAsset::Register(ToString(fontSize), fontSize, Typeface::Medium);
	}

	while (System::Update())
	{
		Ash::showFPS();
	}
}